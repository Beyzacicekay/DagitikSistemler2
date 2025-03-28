#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int veri = 0;

    MPI_Init(&argc, &argv);                   
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);     
    MPI_Comm_size(MPI_COMM_WORLD, &size);     

    if (rank == 0) {
        printf("===============================================================\n");
        printf("=============== MPI + OpenMP İşlem Akışı =====================\n\n");

        veri = 0;
        printf("[Master] Başlangıç değeri: %d\n", veri);

        int gonderilecek = 10;
        MPI_Send(&gonderilecek, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("[Master] İşlenecek ilk veri: %d → Düğüm 1'e gönderildi\n\n", gonderilecek);

        int son;
        MPI_Recv(&son, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("✅ [Master] Nihai sonuç başarıyla alındı: %d\n", son);

        printf("\n===============================================================\n");

    } else {
        int alinan;
        MPI_Recv(&alinan, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("[Düğüm %d] Veri alındı: %d\n", rank, alinan);

        int yeni = alinan;
        printf("[Düğüm %d] OpenMP ile 4 thread çalışıyor...\n", rank);

        #pragma omp parallel for
        for (int i = 0; i < 4; i++) {
            // Thread loglama istenirse buraya yazılır
            #pragma omp critical
            printf("[Düğüm %d] Thread %d işliyor...\n", rank, i);
            yeni += 5;
        }

        printf("[Düğüm %d] Güncellenmiş veri: %d\n", rank, yeni);

        if (rank == size - 1) {
            MPI_Send(&yeni, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
            printf("[Düğüm %d] Nihai sonuç, Master'a geri gönderildi\n\n", rank);
        } else {
            MPI_Send(&yeni, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
            printf("[Düğüm %d] Veri, Düğüm %d'ye gönderildi\n\n", rank, rank + 1);
        }
    }

    MPI_Finalize();
    return 0;
}

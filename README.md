# 🧠 MPI + OpenMP Dağıtık Paralel Programlama Örneği

Bu proje, **MPI (Message Passing Interface)** ve **OpenMP (Open Multi-Processing)** teknolojilerini bir arada kullanarak dağıtık sistemde paralel işlemeyi simüle eden bir örnektir. Docker ortamında çalışacak şekilde yapılandırılmıştır.

---

## 🎯 Amaç

- MPI ile düğümler (nodes) arasında veri aktarımı gerçekleştirmek.
- Her düğümde OpenMP ile paralel işlem yapmak.
- Sonuçları sırayla işleyip en sonunda master düğüme ulaştırmak.


---

## 🐳 Docker Yapısı

Docker, uygulamanın her düğümünü (node) izole bir ortamda çalıştırır. Projemizde her konteyner:

- `Ubuntu` tabanlıdır.
- Gerekli MPI ve OpenMP kütüphanelerini içerir.
- `main.c` dosyasını `mpicc` ile derler.
- `mpirun` komutuyla çalıştırılır.

Bu sayede platform bağımsız, taşınabilir ve hızlı kurulum yapılabilir.

---

## 🧱 Docker Compose Yapısı

Docker Compose ile:

- 1 adet `mpi_master` konteyneri (ana işlem)
- 3 adet `worker` konteyneri (yardımcı düğümler)

aynı `bridge` ağında birlikte çalışacak şekilde ayağa kaldırılır. Tüm işlemler tek bir komutla (`docker-compose up`) başlatılır ve merkezi kontrol sağlanır.

---

## ⚖️ MPI vs OpenMP Performans Karşılaştırması

| Kriter         | MPI                               | OpenMP                             |
|----------------|------------------------------------|-------------------------------------|
| **Paralellik** | Dağıtık sistemlerde kullanılır     | Aynı işlemci üzerinde thread bazlı |
| **İletişim**   | Mesajlaşma ile veri aktarımı       | Paylaşılan bellek kullanımı        |
| **Performans** | Yüksek işlem gücü ama iletişim maliyetli | Hızlı veri paylaşımı, sınırlı çekirdek |
| **Ölçeklenebilirlik** | Yüksek (farklı makineler)       | Düşük (tek makine/CPU ile sınırlı) |

**Sonuç:**  
- Küçük işlemlerde OpenMP daha hızlıdır.
- Büyük, dağıtık sistemlerde MPI ile daha yüksek verim alınır.
- Bu projede ikisi bir arada kullanılarak hem düğümler arası hem de çekirdek içi paralellik sağlanmıştır.
## 🎬 Proje Tanıtım Videosu

Bu videoda projenin genel yapısı ve nasıl çalıştığı gösterilmektedir:

[👉 Videoyu İzlemek İçin Tıklayın](https://drive.google.com/file/d/VIDEO_ID/view?usp=sharing)

> 📌 Not: Videoya erişim için paylaşım ayarlarının “Bağlantıya sahip olan herkes görüntüleyebilir” olarak ayarlandığından emin olun.


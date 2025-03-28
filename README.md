# 🧠 MPI + OpenMP Dağıtık Paralel Programlama Örneği

Bu proje, **MPI (Message Passing Interface)** ve **OpenMP (Open Multi-Processing)** teknolojilerini bir arada kullanarak dağıtık sistemde paralel işlemeyi simüle eden bir örnektir. Docker ortamında çalışacak şekilde yapılandırılmıştır.

---

## 🎯 Amaç

- MPI ile düğümler (nodes) arasında veri aktarımı gerçekleştirmek.
- Her düğümde OpenMP ile paralel işlem yapmak.
- Sonuçları sırayla işleyip en sonunda master düğüme ulaştırmak.

---

## 🧱 Proje Yapısı

```plaintext
.
├── Dockerfile
├── docker-compose.yml
├── main.c
└── README.md

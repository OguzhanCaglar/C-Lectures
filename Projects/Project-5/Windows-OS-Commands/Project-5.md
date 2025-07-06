# Windows Komutlarını C ile Yeniden Yazma Projesi

Bu projede, Windows işletim sisteminde sıkça kullanılan bazı temel komutları (örneğin `dir`, `copy`, `del`) C programlama dili ile kendi başımıza nasıl yazabileceğimizi öğreneceğiz. Amaç, bu komutların temel işlevlerini anlamak ve C dilinde uygulamalarını geliştirmektir.

## Proje Amacı

- Windows komutlarının çalışma mantığını kavramak
- C dilinde dosya ve dizin işlemlerini öğrenmek
- Temel sistem programlama becerilerini geliştirmek

## Hedeflenen Komutlar

- **dir**: Bir dizindeki dosya ve klasörleri listeler.
- **copy**: Dosya veya klasörleri kopyalar.
- **del**: Dosya veya klasörleri siler.

## Proje Yapısı

```
windows-commands-c/
│
├── src/
│   ├── main.c           # Komut satırı arayüzü ve ana program
│   ├── commands/
│   │   ├── dir.c        # 'dir' komutunun C ile yazılmış hali
│   │   ├── copy.c       # 'copy' komutunun C ile yazılmış hali
│   │   └── del.c        # 'del' komutunun C ile yazılmış hali
│   └── include/
│       ├── dir.h
│       ├── copy.h
│       └── del.h
├── Makefile             # Derleme talimatları
└── README.md            # Proje açıklaması (bu dosya)
```

## Nasıl Çalışır?

1. Kullanıcı, komut satırından kendi yazdığımız programı çalıştırır.
2. Program, verilen komutu (`dir`, `copy`, `del`) ve parametreleri algılar.
3. İlgili C fonksiyonu çağrılarak işlem gerçekleştirilir.

## Örnek Kullanım

```
windows-commands-c> mycmd dir C:\Users\Kullanici\Belgeler
windows-commands-c> mycmd copy dosya1.txt dosya2.txt
windows-commands-c> mycmd del gereksiz.txt
```

## Geliştirme Adımları

1. Her komut için ayrı bir C dosyası oluşturun.
2. Dosya ve dizin işlemleri için C'nin standart kütüphanelerini kullanın (`stdio.h`, `stdlib.h`, `dirent.h`, `windows.h`).
3. Komut satırı argümanlarını işleyin.
4. Hataları ve kullanıcıya geri bildirimleri yönetin.

## Katkı ve Geliştirme

Projeye katkıda bulunmak için yeni komutlar ekleyebilir veya mevcut komutları geliştirebilirsiniz. Pull request gönderebilir veya issue açabilirsiniz.

---
Bu proje, temel sistem programlama ve C dilinde dosya/dizin işlemleri konusunda pratik yapmak isteyenler için
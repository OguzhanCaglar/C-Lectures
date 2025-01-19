// Hanoi Kuleleri problemi, bir matematiksel bulmaca olup şu şekilde tanımlanır:

// Giriş: 3 adet çubuk (A, B, C) ve farklı boyutlarda 
// 𝑛
// n adet disk. Diskler başlangıçta en küçük disk en üstte ve en büyük disk en altta olacak şekilde bir çubuğa (örneğin, çubuk A) dizilir.
// Amaç: Disklerin hepsini, verilen kurallara uygun olarak başka bir çubuğa (örneğin, çubuk C) taşımaktır.
// Kurallar:
// Aynı anda yalnızca bir disk taşınabilir.
// Her hareketle, bir disk başka bir çubuğun en üstüne yerleştirilir.
// Hiçbir zaman bir diskin daha küçük bir diskin üzerine yerleştirilmesine izin verilmez.

void hanoi(int n, char source, char target, char auxiliary)
{
    // Temel durum: Eğer yalnızca 1 disk varsa doğrudan hedefe taşı
    if(n == 1)
    {
        printf("Diski %c'den %c'ye tasi\n", source, target);
        return;
    }

    // Adım 1: n-1 diski kaynaktan yardımcıya taşı.
    hanoi(n-1, source, auxiliary, target);

    // Adım 2: En büyük diski kaynaktan hedefe taşı.
    printf("Diski %c'den %c'ye tasi\n", source, target);

    // Adım 3: n-1 diski yardımcıdan hedefe taşı:
    hanoi(n - 1, auxiliary, target, source);
}

int main()
{
    int diskSayisi;

    printf("Disk sayisini girin: ");
    scanf("%d", &diskSayisi);

    printf("Hanoi Kuleleri Cozumu:\n");
    hanoi(diskSayisi, 'A', 'B', 'C');

    return 0;
}
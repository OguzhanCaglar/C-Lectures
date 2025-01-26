// Given an array: a[10] = 21, 3, 5, 8, 5,11, 22,14,51,9}
// Sort the array in ascending order: 3, 5, 5, 8, 9, 11, 14, 21, 22, 51}

/* 
Bubble Sort (Baloncuk Sıralaması) 
--------------------------------------------

Baloncuk sıralaması, temel sıralama algoritmalarındna birsiidr. Dizinin her bir konumundaki elemanı, sırasıyla bir sonraki
konumdaki eleman ile karşılaştırılır. Dizinin küçükten büyuüğe soğru sıralanması istenirse, bu karşılaştırma esnasında mevcut elemanın
sonraki dizi elemanından büyük olup olmadığı kontrol edilir. Bu şartın sağlandığı sonucuna varılırsa iki eleman yer değiştirlir. Aksi durumda ise
herhangi bir yer değiştirme işlemi yapılmaz ve karşılaştırmaya bir sonraki konumdaki dizi elemanı ile devam edilir. Bu işlem dizinin son elemanına
ulaşıncaya kadar sürdürlür. Dizinin başından sonuna doğru yapılan bu karşılaştıma tamamlandığında algoritmanın bir adımı (iterasyonu) tamamlanmış olur.
Sonuç olarak dizinin en büyük elemanı konum olarak dizinin en sonuna yerleşmiş olacaktır. Bu algoritmal adımları n elemanlı bir dizi için n-1 defa
tekrarlandığında tamamen sıralı bir dizi elkde edilmiş olur. 

*/ 

#include <stdio.h>

int main()
{
    int a[10] = {21, 3, 5, 8, 5,11, 22,14,51,9};

    int temp = 0;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < (10 - i - 1); j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            } // if
        } // for(j)
    } // for(i)

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
# 42 get_next_line Projesi

Bu repository, 42 okulu tarafından sunulan Piscine eğitimi sırasında tamamladığım "get_next_line" projesini içerir. "get_next_line", bir dosyadan satır satır veri okuma işlemi gerçekleştiren C programının bir örneğidir.

## Proje Açıklaması

"get_next_line" işlevi, bir dosyadan okunan veriyi bir karakter dizisi (string) halinde döndürür. Her çağrıda, işlev dosyanın bir sonraki satırını okur ve bu satırı döndürür. Eğer dosya sonuna gelinmişse veya okuma işlemi tamamlanmışsa, işlev `NULL` değeri döndürür. Bu işlev, özellikle büyük metin dosyaları okurken veya satır bazında veri işlerken kullanışlıdır.

## Kullanım

"get_next_line" işlevini kullanmak için aşağıdaki adımları izleyebilirsiniz:

1. İşlevin prototipini ekleyin: `int get_next_line(int fd, char **line);`

2. `get_next_line` işlemini bir dosya tanımlayıcısı (`fd`) ve bir karakter dizisi (`line`) ile çağırın.

3. İşlem başarılı ise, `line` karakter dizisi, okunan satırı içerecektir.

4. İşlem sona erdiğinde veya bir hata oluştuğunda, işlem sonlandığını belirten bir değer döndürülür (1: okuma başarılı, 0: dosya sonuna ulaşıldı, -1: hata).

### Örnek

```c
#include "get_next_line.h"

int main() {
    int fd;
    char *line;
    
    fd = open("metin_dosyasi.txt", O_RDONLY);
    if (fd == -1) {
        perror("Dosya açılırken hata oluştu");
        return (1);
    }

    while (get_next_line(fd, &line) > 0) {
        printf("Okunan satır: %s\n", line);
        free(line);
    }

    close(fd);
    return (0);
}

# Sentimental

### Задачі

1. Реалізуйте наступну задачу відповідно до її специфікації, але на мові програмування Python:
   * [Hello](hello.md), у файлі `pset6/hello/hello.py`
2. Реалізуйте будь-яку із наступних задач відповідно до їх специфікації, але на мові програмування Python:
   * [Mario](mario-less.md) (легша версія) у файлі `pset6/mario/mario.py`
   * [Mario](mario-more.md) (скадніша версія) у файлі `pset6/mario/mario.py` 
3. Реалізуйте будь-яку із наступних задач відповідно до їх специфікації, але на мові програмування Python:
   * [Сash](cash.md) (легша задача) у файлі `pset6/cash/cash.py`
   * [Credit](credit.md) (складніша задача) у файлі `pset6/credit/credit.py`
3. Реалізуйте будь-яку (одну) із наступних задач відповідно до їх специфікації, але на мові програмування Python:
   * [Caesar](caesar.md) (легша задача) у файлі `pset6/caesar/caesar.py`
   * [Vigenère](vigenere.md) (легша задача) у файлі `pset6/vigenere/vigenere.py`
   * [Crack](crack.md) (складніша задача) у файлі `pset6/crack/crack.py`

### Відеоінструкція

Зверніть увагу, що за посиланням знаходиться не одне, а вісім відео!

Також зверніть увагу, що у цих інструкціях задача Cash називається Greedy. Також, для задачі Crack, довжина паролю може бути 5 символів (а не 4, як сказано у інструкції).

[Посилання на YouTube](https://www.youtube.com/watch?list=PLhQjrBD2T381raeNI8WdI4D7GMu0XFGTh&v=5ueXMnDE-y8)

### Тестування

#### Коректність

```bash
check50 cs50/2018/x/sentimental/hello
check50 cs50/2018/x/sentimental/mario/less
check50 cs50/2018/x/sentimental/mario/more
check50 cs50/2018/x/sentimental/cash
check50 cs50/2018/x/sentimental/credit
check50 cs50/2018/x/sentimental/caesar
check50 cs50/2018/x/sentimental/vigenere
```

Як і раніше, для задачі Crack не передбачено перевірки із `check50`, адже це може зіпсувати вам задоволення!

#### Стиль

```bash
style50 hello.py
style50 mario.py
style50 cash.py
style50 credit.py
style50 caesar.py
style50 vigenere.py
style50 crack.py
```

### Підказки

* Переконайтесь, що ви використовуєте Python 3 а не Python 2. Python 3 встановлено за замовчуванням у CS50 IDE, але якщо ви гуглите офіційну документацію Python, переконайтесь, що URL починається з https://docs.python.org/3/ а не з https://docs.python.org/2/.

* Якщо ваша програма називається, скажімо, `foo.py`, ми можете її виконати командою `python foo.py`.

* Для задач Hello, Mario, Greedy, Credit, Caesar, Vigenère і Crack, ми вважаємо дозволеним для вас дивитись на ваші розв'язки цих задач на C чи на розв'язки ваших колег на C. Ми **не** вважаємо дозволеним для вас дивитись на розв'язки цих задач іншими людьми на Python.

* Розглядайте цю задачу не тільки як можливість портувати вашу попередню роботу із C на Python, але і як щанс покращити дизайн ваших попередніх розв'язків, використовуючи знання, отримані з тих пір!

* Під час портування коду із C на Python у CS50 IDE, ви можете використати  **View > Layout > Horizontal Split** для того, щоб бачити обидва файлі один поряд з іншим.

* Так як ціль цієї задачі навчити вас, як вам самостійно вивчати нову мову програмування, пам'ятайте, що ми не тільки дозволяємо робити наступні дії - ми заохочуємо вас робити їх. Ви можете:

    * Використовувати декілька рядків коду, які ви знайшли онлайн чи будь-де, у вашому коді при умові, що ці рядки не є власне розв'язком задачі і при умові, що ви вказуєте джерело. 
    * Використовувати web-сайти чи будь-які інші джерела для того, щоб отримати інструкції поза межами курсу щодо довідок чи розв'язків технічних складностей, але **не** щодо прямих розв'язків поставлених задач. 


* Ми запрошуємо вас використовувати бібліотеку CS50 для Python, яка включає в себе `get_float`, `get_int` і `get_string`. Для цього додайте відповідні рядки згори у вашому коді:

``` python
from cs50 import get_float
from cs50 import get_int
from cs50 import get_string
```

Ви також можете використовувати [`input`](https://docs.python.org/3/library/functions.html#input) і перевіряти вхідні дані користувачів власноруч.

* Вам можуть знадобитись такі функції, як [chr](https://docs.python.org/3/library/functions.html#chr) і/або [ord](https://docs.python.org/3/library/functions.html#ord).

* Вам можуть знадобитись наступні посилання:
    * [Довідник мови програмування Python](https://docs.python.org/3/reference/index.html)
    * [Стандартна бібліотека мови програмування Python](https://docs.python.org/3/library/)
    * [Навчальні матеріали з мови програмування Python](https://docs.python.org/3/tutorial/index.html)

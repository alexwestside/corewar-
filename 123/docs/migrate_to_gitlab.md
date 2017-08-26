# Міграція на gitlab

1. Додати в профіль на gitlab SSH-ключ (для роботи треба використовувати ssh-підключення,
бо цей варіант стабільніший).

2. Перевірити, чи конектиться:

        ssh -T git@gitlab.com

3. Закрити IDE.

4. Зробити резервну копію робочої папки.

5. Видалити робочу папку.

6. Стягнути репозиторій:

        git clone git@gitlab.com:COREWAR_ASMM/corewar.git

7. Перевірити і налаштувати юзернейм та мейл (бажано, щоб співпадав з тим, що в gitlab):

        cd corewar
        git config -l
        git config user.name "Your Name"
        git config user.email "your@email"


8. Переключитись на свою робочу гілку:

        git checkout 'name_your_working_branch'

9. Відновити з резервної копії папки/файли вашого IDE.

10. Запустити IDE.

11. Ознайомитись з новим workflow.

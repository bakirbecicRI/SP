#include <iostream>
#include <queue>

int main() {
  std::queue<int> transactions;
  int choice;
  int balance = 0;
  do {
    std::cout << "Choose an option:" << std::endl;
    std::cout << "1. Add transaction" << std::endl;
    std::cout << "2. Apply transaction" << std::endl;
    std::cout << "3. Apply only positive transactions" << std::endl;
    std::cout << "4. Apply transactions until first negative" << std::endl;
    std::cout << "5. Check balance" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Enter the option number: ";
    std::cin >> choice;
    std::cout << std::string('-', 30);
    if (choice == 1) {
      int num;
      std::cout << "Enter the amount of transaction: ";
      std::cin >> num;
      transactions.push(num);
    } else if (choice == 2) {
      if (!transactions
               .empty()) { // ovdje dobijes samo ovo u 26. i 27. liniji, ostatak
                           // moras dodat. Znaci provjeri ako balans ode u nulu
                           // vrati ga u pocetno stanje i prebaci tu vrijednost
                           // sto si dodavala na kraj queuea sa ovim pushom.
        balance += transactions.front();
        if (balance < 0) {
          balance = balance- transactions.front();
          std::cout << "Nije moguce izvrsiti transakciju. " << std::endl;
          transactions.push(transactions.front());
        }
        transactions
            .pop(); // ovo uvijek radis da uklonis element sa kraja queuea.
      }
    } else if (choice ==
               3) { // ovdje samo pozitivne treba dodavat, znaci kad naletis na
                    // negativan balans samo vrati u pocetno stanje i preskoci
      while (!transactions.empty()) {
        balance += transactions.front();
        if (balance < 0) {
          balance = balance - transactions.front();
        }
        transactions.pop();
      }
    } else if (choice == 4) { // ovdje dodaje elemente sve dok ne naleti na
                              // negativan, kad naleti stopiraj.
      while (!transactions.empty()) {
        balance += transactions.front();
        if (balance < 0) {
          balance = balance - transactions.front();
          break;
        }
        transactions.pop();
      }
    } else if (choice == 5) {
      std::cout << "Balance: " << balance << std::endl;
    } else if (choice == 6) {
      std::cout << "Exiting the program." << std::endl;
    } else {
      std::cout << "Invalid option, please enter again." << std::endl;
    }
  } while (choice != 6);

  return 0;
}

/*
 queue
 izlaz <----- 1 2 3 4 5 <----- ulaz
 pop treba da izbaci 1. Push treba da doda nesto iza 5.
 U zadatku kaze ako balans ode u nulu, ta transakcija ne treba da se izvrsi nego
treba da se proslijedi na kraj queuea. Znaci, ako balans ode negativno, 1
svakako popaj, i prebaci ga na pocetak queuea, znaci iza petice.

 2 3 4 5 1


cijeli zadatak je ispisan, sve se implementira u mainu, samo ti trebas dodat i
napravit choice 3 i choice 4. choice 2 dobijes dio uradjen, ti trebas izmijenit
tako da balans ne smije otic u nulu, ako ode vrati ga u prethodno stanje i
prebaci tu vrijednost na kraj reda.



 */

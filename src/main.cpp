#include <iostream>

#include "model/order.h"
#include "model/store.h"
#include "model/person.h"
#include "model/product.h"

#include <iostream>

#include <map>


int main() {
    Cake meatCake("Bolo com molho de carne", 1.20, "gostoso");
    Bread hugeBread("aquele pão gostoso", 0.15, false);
    std::map<Product*,unsigned> products;
    //products[meatCake] = 2;
    //products[hugeBread] = 3;
    //Order Order(products);

    std::cout << "ta a tchober tchouricas";


    return 0;
}


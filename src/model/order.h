//
// Created by laimi on 15/10/2020.
//

#ifndef SRC_ORDER_H
#define SRC_ORDER_H

#include <utility>
#include <vector>
#include <ctime>
#include <iostream>
#include <map>

#include "../exception/product_exception.h"
#include "../exception/order_exception.h"

#include "person.h"
#include "product.h"
#include "date.h"

class Person;
class Client;
class Worker;

class Order {
public:
    Order(Client& client, Worker& worker, std::map<Product*, unsigned int>  products = {}, Date date = {});

    bool hasDiscount() const;
    bool wasDelivered() const;

    const Worker& getWorker() const;
    const Client& getClient() const;

    std::map<Product*, unsigned int> getProducts() const;
    bool hasProduct(Product* product);

    void addProduct(Product* product, unsigned quantity = 1);
    void removeProduct(Product* product, unsigned quantity);
    void removeProduct(Product* product);

    float getClientEvaluation() const;
    float getFinalPrice() const;
    float getTotal() const;

    Date getDate() const;

    void deliver(float clientEvaluation);
private:
    void updateTotalPrice();
    std::map<Product*, unsigned int> _products;
    float _totalPrice;
    Client& _client;
    Worker& _worker;
    float _clientEvaluation;
    bool _delivered;
    Date _date;
};

#endif //SRC_ORDER_H

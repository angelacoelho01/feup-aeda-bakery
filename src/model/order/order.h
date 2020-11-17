//
// Created by laimi on 15/10/2020.
//

#ifndef SRC_ORDER_H
#define SRC_ORDER_H

#include "exception/product_exception.h"
#include "exception/order_exception.h"

#include "model/person/person.h"
#include "model/product/product.h"
#include "model/product/product_manager.h"
#include "model/date/date.h"

#include <fstream>
#include <map>


class Order {
public:
    Order(Client& client, Worker& worker, Date date = {});

    bool hasDiscount() const;
    bool hasProduct(Product* product);
    bool wasDelivered() const;

    Worker* const getWorker() const;
    Client* const getClient() const;

    std::map<Product*, unsigned int, ProductSmaller> getProducts() const;

    int getClientEvaluation() const;
    float getFinalPrice() const;
    float getTotal() const;

    Date getRequestDate() const;
    Date getDeliverDate() const;

    Product* addProduct(Product* product, unsigned quantity = 1);
    void removeProduct(Product* product, unsigned quantity);
    void removeProduct(Product* product);
    void removeProduct(unsigned position, unsigned quantity);
    void removeProduct(unsigned position);

    void deliver(int clientEvaluation, int deliverDuration = 30);

    bool operator==(const Order& rhs) const;
    bool operator<(const Order& rhs) const;

    void print(std::ostream& os) const;

private:
    std::map<Product*, unsigned int, ProductSmaller> _products;
    void updateTotalPrice();
    float _totalPrice;
    Client* _client;
    Worker* _worker;
    int _clientEvaluation;
    bool _delivered;
    Date _requestDate;
    Date _deliverDate;
};

#endif //SRC_ORDER_H

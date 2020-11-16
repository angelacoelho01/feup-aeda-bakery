//
// Created by bdmendes on 29/10/20.
//

#include "order_manager.h"

OrderManager::OrderManager(ProductManager &pm, ClientManager &cm, WorkerManager &wm) :
        _productManager(pm), _clientManager(cm), _workerManager(wm), _orders(std::vector<Order*>()){
}

bool OrderManager::has(Order *order) const {
    auto it = std::find_if(_orders.begin(), _orders.end(), [order](const Order* o){
        return *o == *order;
    });
    return it != _orders.end();
}

Order* OrderManager::get(unsigned int position) {
    if (position >= _orders.size()) throw InvalidOrderPosition(position, _orders.size());
    auto it = _orders.begin(); std::advance(it, position);
    return *it;
}

std::vector<Order *> OrderManager::getAll() const {
    return _orders;
}

std::vector<Order *> OrderManager::get(Client *client) {
    if (!_clientManager.has(client)) throw PersonDoesNotExist(client->getName(), client->getTaxId());
    std::vector<Order*> filtered;
    for (const auto& order: _orders){
        if (order->getClient() == *client) filtered.push_back(order);
    }
    return filtered;
}

std::vector<Order *> OrderManager::get(Worker *worker) {
    if (!_workerManager.has(worker)) throw PersonDoesNotExist(worker->getName(), worker->getTaxId());
    std::vector<Order*> filtered;
    for (const auto& order: _orders){
        if (order->getWorker() == *worker) filtered.push_back(order);
    }
    return filtered;
}

void OrderManager::sort() {
    std::sort(_orders.begin(), _orders.end());
}

Order* OrderManager::add(Client *client) {
    if (!_clientManager.has(client)) throw PersonDoesNotExist(client->getName(), client->getTaxId());
    _orders.push_back(new Order(*client,*_workerManager.getAvailable()));
    return *_orders.rbegin();
}

Order* OrderManager::add(Client *client, Date date) {
    if (!_clientManager.has(client)) throw PersonDoesNotExist(client->getName(), client->getTaxId());
    _orders.push_back(new Order(*client,*_workerManager.getAvailable(), date));
    return *_orders.rbegin();
}

void OrderManager::remove(Order *order) {
    auto position = std::find(_orders.begin(),_orders.end(),order);
    if (position == _orders.end())
        throw OrderDoesNotExist();
    _orders.erase(position);
}

void OrderManager::print(std::ostream &os) const {
    int numSpaces = static_cast<int>(std::to_string(_orders.size()).size() + 2);
    os << std::string(numSpaces,util::SPACE) << util::column("CLIENT",true)
    << util::column("WORKER",true)
    << util::column("REQUESTED",true)
    << util::column("DELIVERED",true) << "\n";

    int count = 1;
    for (const auto& o: _orders){
        os << std::setw(numSpaces) << std::left << std::to_string(count) + ". "
        << util::column(o->getClient().getName(),true)
        << util::column(o->getWorker().getName(),true)
        << util::column(o->getRequestDate().getCompleteDate(), true)
        << util::column(o->wasDelivered() ? o->getDeliverDate().getClockTime() + " (" +
        util::to_string(o->getClientEvaluation()) + " points)" : "Not Yet",true) << "\n";
        count++;
    }
}

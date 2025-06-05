#include "Order.h"
#include "OrderBook.h"
#include <deque>
#include <iostream>
#include <algorithm>


void OrderBook::addBuyOrder(const Order &buyOrder) {
    buyOrders.push_back(buyOrder);
    mapOrderIdOperation[Order::OrderOperation::BUY].insert(buyOrder.getId());
}


void OrderBook::addSellOrder(const Order &sellOrder) {
    sellOrders.push_back(sellOrder);
    mapOrderIdOperation[Order::OrderOperation::SELL].insert(sellOrder.getId());
}

void OrderBook::matchOrders()  {
        auto buyIT = buyOrders.begin();
        auto sellIT = sellOrders.begin();
        while(buyIT!= buyOrders.end() && sellIT != sellOrders.end()){
			Order &buyOrder = *buyIT;
			Order &sellOrder = *sellIT;
            idNumOfBuyOrder = stoi(buyOrder.getId().substr(sizeOfOrderWord,sizeOfOrderWord-buyOrder.getId().size()));
            idNumOfSellOrder= stoi(sellOrder.getId().substr(sizeOfOrderWord,sizeOfOrderWord-sellOrder.getId().size()));
			if (buyOrder.getPrice() >= sellOrder.getPrice()){
				matchedQuantity = std::min(buyOrder.getQuantity(), sellOrder.getQuantity());
                std::cout << "TRADE " ;
                if (idNumOfBuyOrder <idNumOfSellOrder){
                    std::cout << buyOrder << sellOrder <<std::endl;
                }else{
                    std::cout << sellOrder << buyOrder<<std::endl;
                }
                bool fullMatchBuyOrder = adjustOrderQuantity(buyOrder, buyOrders, matchedQuantity);
                bool fullMatchSellOrder= adjustOrderQuantity(sellOrder, sellOrders, matchedQuantity);
                if (fullMatchBuyOrder) {
                    buyIT = buyOrders.erase(buyIT);
                }
                if (fullMatchSellOrder) {
                    sellIT = sellOrders.erase(sellIT); 
                }
			}else{
                buyIT++;
            }
        }
};

bool OrderBook::adjustOrderQuantity(Order &order, std::deque<Order> &ordersDeque, const int matchedQuantity){
    if(order.getQuantity() > matchedQuantity){
        order.setQuantity((order.getQuantity()-matchedQuantity));
        return false;
    }
    return true;

};

void OrderBook::modifyOrder(std::string orderId, Order::OrderOperation modifyOrderOperation, int newPrice, int newQuantity){
    Order::OrderOperation orderType;
    for (const auto &pair: mapOrderIdOperation){
        for (std::string value: pair.second){
            if (value == orderId){
                orderType = pair.first;
                break;
        }
        }

    }

    std::deque<Order>* ordersToModify = (orderType == Order::OrderOperation::BUY) ? &buyOrders : &sellOrders;
    std::deque<Order>* oppositeOrders = (orderType == Order::OrderOperation::BUY) ? &sellOrders : &buyOrders;
    Order::OrderOperation currentOperation = (orderType == Order::OrderOperation::BUY) ? Order::OrderOperation::BUY : Order::OrderOperation::SELL;
    for (auto it = ordersToModify->begin(); it != ordersToModify->end(); ++it) {
        if (it->getId() == orderId) {
            if (modifyOrderOperation == currentOperation) {
                ordersToModify->emplace_back(Order(it->getId(), currentOperation, newPrice, newQuantity));
            } else {
                oppositeOrders->emplace_back(Order(it->getId(), modifyOrderOperation, newPrice, newQuantity));
                mapOrderIdOperation[currentOperation].erase(orderId);
                mapOrderIdOperation[modifyOrderOperation].insert(orderId);
            }
            ordersToModify->erase(it);
            break;
        }
    }
};

void OrderBook::printOrders(){
    std::cout << "===========" << std::endl;
    std::cout <<"BUY: " <<std::endl;
    for(const Order &buyOrder: buyOrders){
        std::cout << buyOrder << std::endl;
    }
    std::cout << "===========" << std::endl;
    std::cout <<"SELL: " <<std::endl;
    for (const Order &sellOrder: sellOrders){
        std::cout <<sellOrder <<std::endl;
    }
    std::cout << "===========" << std::endl;
}

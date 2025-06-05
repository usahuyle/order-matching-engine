#include "I_Order.h"
#include "Order.h"
#include <deque>
#include <map>
#include <set>
#ifndef _ORDERBOOK_H_
#define _ORDERBOOK_H_
class OrderBook: public I_OrderBook{
    private:
        int matchedQuantity;
        int idNumOfBuyOrder;
        int idNumOfSellOrder;
        const int sizeOfOrderWord{5};
        std::deque<Order> buyOrders;
        std::deque<Order> sellOrders;
        std::map<Order::OrderOperation, std::set<std::string>> mapOrderIdOperation;
        void addBuyOrder(const Order &buyOrders) override;
        void addSellOrder(const Order &sellOrders) override;
        void modifyOrder(std::string orderId, Order::OrderOperation orderOperation, int newPrice, int newQuantity) override;
        void matchOrders() override;
        bool adjustOrderQuantity(Order &order,std::deque<Order> &ordersDeque,const int matchedQuantity);
        void printOrders() override;
    
};

#endif
#include "I_Order.h"
#ifndef _ORDERENGINE_H_
#define _ORDERENGINE_H_
class OrderEngine{
    public:
        OrderEngine(I_OrderBook *orderbook);
        void addBuyOrder(const Order &buyOrders);
        void addSellOrder(const Order &sellOrders);
        void matchOrders();
        void modifyOrder(std::string orderId,Order::OrderOperation modifyOrderOperation, int newPrice, int newQuantity);
        void modifyOrder(const Order &modifyOrder);
        void printOrders();
    private:
        I_OrderBook *orderbook;
};
#endif
#ifndef _I_ORDER_H_
#define _I_ORDER_H_
#include "Order.h"
class I_OrderBook{
public:
    virtual void addBuyOrder(const Order &buyOrder)=0;
    virtual void addSellOrder(const Order &sellOrder)=0;
    virtual void matchOrders()=0;
    virtual void modifyOrder(std::string orderId, Order::OrderOperation modifyOrderOperation, int newPrice, int newQuantity)=0;
    virtual void printOrders()=0;
    virtual ~I_OrderBook()=default;
};
#endif


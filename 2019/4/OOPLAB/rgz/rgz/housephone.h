#ifndef HOUSEPHONE_H
#define HOUSEPHONE_H
#pragma once
#include <QtWidgets>
#include "ApartmentsPanel.hpp"
#include "ApartmentSelect.hpp"
#include "FrontDoor.hpp"
#include "LogWindow.hpp"

class House{
    int apart_per_floor,floors;
    int correct_key;
    ApartmentSelect* house;
    FrontDoorPanel* panel;
    LogWindow* log;
    public:
    House(int apf,int f, int key):apart_per_floor(apf),floors(f),correct_key(key){
        house = new ApartmentSelect(7,3);
        panel = new FrontDoorPanel(1323);
        log = new LogWindow();
        QObject::connect(house,SIGNAL(open_door(int)),log,SLOT(record_open_door(int)));
        QObject::connect(house,SIGNAL(open_conn(int)),log,SLOT(record_connect_open(int)));
        QObject::connect(house,SIGNAL(close_conn(int)),log,SLOT(record_connect_close(int)));
        QObject::connect(panel,SIGNAL(record_open_door(int)),log,SLOT(record_open_with_key(int)));
        QObject::connect(panel,SIGNAL(record_wrong_key(int)),log,SLOT(record_wrong_key(int)));
        QObject::connect(panel,SIGNAL(b_call_click()),house,SLOT(show()));
        panel->show();
        log->show();
    };
};

class HouseBuilder{
    int aparts = 2;
    int floors = 2;
    int key = 1234;
    public:
        void set_floors(int num){
            this->floors = num;
        };
        void set_aparts(int num){
            this->aparts = num;
        }
        void set_key(int num){
            this->key = num;
        }
        House build(){
            return House(aparts,floors,key);
        };
};

class HouseConfig{
    QFile* config;
    QTextStream cfg;
    int aparts,floors,key;
    HouseBuilder builder;
    public:
        HouseConfig(){
            config = new QFile("config.cfg");
            config->open(QIODevice::ReadOnly);
            cfg.setDevice(config);
            cfg>>aparts>>floors>>key;
            builder.set_aparts(aparts);
            builder.set_floors(floors);
            builder.set_key(key);
        };
        House get_result(){
            return builder.build();
        };
};
#endif // HOUSEPHONE_H

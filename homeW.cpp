#include <iostream>
#include <string>

// Абстрактный класс для автомобилей
class AbstractTransportCar {
public:
	virtual ~AbstractTransportCar() = default;
	virtual std::string deliveryCar() const = 0;
};

// Конкретная реализация автомобиля
class Car : public AbstractTransportCar {
public:
	std::string deliveryCar() const override {
		return "производится доставка по суше";
	}
};

// Абстрактный класс для кораблей
class AbstractTransportShip {
public:
	virtual ~AbstractTransportShip() = default;
	virtual std::string deliveryShip() const = 0;
};

// Конкретная реализация корабля
class Ship : public AbstractTransportShip {
public:
	std::string deliveryShip() const override {
		return "производится доставка по морю";
	}
};

// Абстрактный класс для самолетов
class AbstractTransportAir {
public:
	virtual ~AbstractTransportAir() = default;
	virtual std::string deliveryAir() const = 0;
};

// Конкретная реализация самолета
class AirPlane : public AbstractTransportAir {
public:
	std::string deliveryAir() const override {
		return "производится доставка по небу";
	}
};

// Абстрактная фабрика для транспортных средств
class AbstractFactory {
public:
	virtual ~AbstractFactory() = default;
	virtual AbstractTransportCar* CreateFactoryCar() const = 0;
	virtual AbstractTransportShip* CreateFactoryShip() const = 0;
	virtual AbstractTransportAir* CreateFactoryAir() const = 0;
};

// Фабрика для создания автомобилей
class ConcreteFactory : public AbstractFactory {
public:
	AbstractTransportCar* CreateFactoryCar() const override {
		return new Car();
	}

	AbstractTransportShip* CreateFactoryShip() const override {
		return new Ship;  // Вернем nullptr, если эта фабрика не поддерживает создание кораблей
	}

	AbstractTransportAir* CreateFactoryAir() const override {
		return new AirPlane;  // Вернем nullptr, если эта фабрика не поддерживает создание самолетов
	}
};


int main() {
	setlocale(LC_ALL, "");
	// Создаем фабрику автомобилей
	AbstractFactory* factory = new ConcreteFactory();

	// Используем фабрику для создания автомобиля
	AbstractTransportCar* car = factory->CreateFactoryCar();
	if (car) {
		std::cout << car->deliveryCar() << std::endl;
		delete car;  
	}

	AbstractTransportShip* ship = factory->CreateFactoryShip();
	if (ship) {
		std::cout << ship->deliveryShip() << std::endl;
	}

	AbstractTransportAir* air = factory->CreateFactoryAir();
	if (air) {
		std::cout << air->deliveryAir() << std::endl;
	}



	delete factory;  

	return 0;
}

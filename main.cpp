#include <iostream>

using namespace std;

class CarStateAlert;
class AlertStateContext;
class Drive;
class Reverse;
class Park;
class Neutral;

class CarStateAlert {
public:
	virtual void alert(AlertStateContext *ctx) = 0;
	virtual void alertType() = 0;

  virtual ~CarStateAlert() {}
};

class Drive : public CarStateAlert {
public:
	void alert(AlertStateContext *ctx) {
		cout << "Drive...\n";
	}
	void alertType() {
		cout << "Set to Drive \n";
	}
};

class Reverse : public CarStateAlert {
public:
	void alert(AlertStateContext *ctx) {
		cout << "Reverse...\n";
	}
	void alertType() {
		cout << "Set to Reverse \n";
	}
};

class Park : public CarStateAlert {
public:
	void alert(AlertStateContext *ctx) {
		cout << "Locked in postition...\n";
	}
	void alertType() {
		cout << "Set to Park \n";
	}
};

class Neutral : public CarStateAlert {
public:
	void alert(AlertStateContext *ctx) {
		cout << "Free to move...\n";
	}
	void alertType() {
		cout << "Set to Neutral \n";
	}
};

class AlertStateContext {
private:
	CarStateAlert *currentState;

public:
	AlertStateContext(CarStateAlert *state) {
		currentState = state;
	}

	void setState(CarStateAlert *state) {
		currentState = state;
	}

	CarStateAlert *getState() {
		return currentState;
	}

	void alert() {
		currentState->alert(this);
	}
};

int main() {
  CarStateAlert* drive = new Drive;
	AlertStateContext *stateContext = new AlertStateContext(drive);
	stateContext->getState()->alertType();
	stateContext->alert();
	stateContext->alert();
  CarStateAlert* reverse = new Reverse;
	stateContext->setState(reverse);
	stateContext->getState()->alertType();
	stateContext->alert();
	stateContext->alert();
	stateContext->alert();
  CarStateAlert* park = new Park;
  stateContext->setState(park);
	stateContext->getState()->alertType();
	stateContext->alert();
	stateContext->alert();
	stateContext->alert();
  stateContext->setState(reverse);
	stateContext->getState()->alertType();
	stateContext->alert();
	stateContext->alert();
	stateContext->alert();
CarStateAlert* neutral = new Neutral;
  stateContext->setState(neutral);
	stateContext->getState()->alertType();
	stateContext->alert();
	stateContext->alert();
	stateContext->alert();
  delete reverse;
  stateContext->setState(drive);
	stateContext->getState()->alertType();
	stateContext->alert();
	stateContext->alert();
	stateContext->alert();
  delete drive;
}
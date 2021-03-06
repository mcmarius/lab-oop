#pragma once

#include <iostream>

int mutate(int k);

enum class CreatureType { PREDATOR, PREY, NOTHING };

class Creature {
public:

  Creature();
  Creature(int, bool, int, int);
  virtual ~Creature() = 0;

  virtual void updateHealth() = 0;
  void updateHealth(int);

  bool isAlive() const; 
  bool isIll() const;
  void makeIll();
  int getHealth() const;

protected:
  int health;
  bool ill;
  const int MAX_HEALTH;
  const int HEALTH_TIC;
};

class Prey: public Creature {
public:

  Prey(int mh = 10, int ht = 1);
  Prey(const Prey&);

  void resetHealth();
  bool canReproduce() const;
  void updateHealth() override;
};

class Predator: public Creature {
public:

  Predator(int mh = 10, int ht = 1);
  Predator(const Predator&);

  void updateHealth() override;
};

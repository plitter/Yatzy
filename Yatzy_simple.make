#Yatzy_simple.make

Yatzy_simple: Yatzy_6_terninger.o 
	g++ -o Yatzy_simple Yatzy_6_terninger.o

YatzyBoard.o: YatzyBoard.cpp YatzyBoard/Alike.h YatzyBoard/Chance.h YatzyBoard/FirstSix.h YatzyBoard/House.h \
            YatzyBoard/PointClass.h YatzyBoard/Straight.h YatzyBoard/TwoPair.h YatzyBoard/Yatzy.h
	g++ -c YatzyBoard.cpp YatzyBoard/Alike.h YatzyBoard/Chance.h YatzyBoard/FirstSix.h YatzyBoard/House.h \
            YatzyBoard/PointClass.h YatzyBoard/Straight.h YatzyBoard/TwoPair.h YatzyBoard/Yatzy.h

DiceArray.o: DiceArray.cpp Dice.h
	g++ -c DiceArray.cpp Dice.h

Yatzy_6_terninger.o: Yatzy_6_terninger.cpp DiceArray.h YatzyBoard.h
	g++ -c Yatzy_6_terninger.cpp DiceArray.h Yatzyboard.h



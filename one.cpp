#include <iostream>
#include <bitset>

enum SuitStatus {
    INVISIBILITY = 0,    // Невидимость
    SILENCE = 1,         // Беззвучие
    INFRARED = 2,        // Подавление ИК-спектра
    RADIO = 3,           // Подавление радиоволн
    ENERGY_SAVING = 4    // Энергосберегающий режим
};


void toggleState(std::bitset<5> &suit, int index) {
    suit.flip(index);
}


bool isActive(std::bitset<5> suit, int index) {
    return suit.test(index);
}


int countActive(std::bitset<5> suit) {
    return (int)suit.count();
}


bool isDetected(std::bitset<5> suit) {
    // Пример 1: Если невидимость выключена, вас точно заметят мармеладовые ослы
    if (!suit.test(INVISIBILITY)) {
        return true;
    }

    // Пример 2: Если вы невидимы, но не подавляете ни звук, ни радиоволны,
    // датчики базы вас зафиксируют
    if (!suit.test(SILENCE) && !suit.test(RADIO)) {
        return true;
    }

    // Пример 3: Если включен энергосберегающий режим,
    // маскировка ИК-спектра может работать нестабильно (условно считаем обнаружением)
    if (suit.test(ENERGY_SAVING) && !suit.test(INFRARED)) {
        return true;
    }

    return false;
}

int main() {
    
    std::bitset<5> pipGirl;
    
    toggleState(pipGirl, INVISIBILITY); 
    toggleState(pipGirl, INFRARED); 
    
    bool checkInvis = isActive(pipGirl, INVISIBILITY); 
    int activeCount = countActive(pipGirl);  

    bool dangerStatus = isDetected(pipGirl); 

    toggleState(pipGirl, SILENCE);
    dangerStatus = isDetected(pipGirl);

    return 0;
}
#ifndef LedMatrix_h
#define LedMatrix_h
 
#include "Arduino.h"
#include "SerialShiftRegisters.h"

class LedMatrix {
	public:
		/*
			ssr - экземпляр класса для общения с регистром сдвига, colCount - количество столбцов, rowCount - количество строк, 
			*ptrPins - ссылка на массив с настройками соответствия пинов и строк/столбцов
				пример [Пин первого столбца, ..., пин colCount столбца, пин первой строки, ..., пин rowCount строки], длина массива colCount + rowCount
			anodeRow - если true - то строки подключены к аноду, иначе строки подключены к катоду
		*/
		
		
		void Initialize(SerialShiftRegisters ssr, int colCount, int rowCount, int *ptrPins, bool anodeRow);
		
		void Clear();
		void Fill();
	private:
		//Признак инициализации класса
		bool _initialized = false;
		
		bool _anodeRow;

		//Объект для управления сдвиговым регистром
		SerialShiftRegisters _ssr;
		
		//Число столбцов и строк в матрице
		int _colCount, _rowCount;
		
		//Ссылка на массив с глобальными номерами пинов сдвиговых регистров
		int *_ptrPins;
};

#endif
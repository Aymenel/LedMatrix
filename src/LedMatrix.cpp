#include "Arduino.h"
#include "SerialShiftRegisters.h"
#include "LedMatrix.h"

void LedMatrix::Initialize(SerialShiftRegisters ssr, int colCount, int rowCount, int *ptrPins, bool anodeRow) {
	_ssr = ssr;

	_colCount = colCount;
	_rowCount = rowCount;

	_ptrPins = ptrPins;

	_anodeRow = anodeRow;

	_initialized = true;
}

void LedMatrix::Clear() {
	//Цикл по пинам столбцов
	for(int i = 0; i < _colCount; i++) {
		_ssr.SetGlobal(_ptrPins[i], _anodeRow);
	}

	//Цикл по пинам строк
	for(int i = _colCount; i < _colCount + _rowCount; i++) {
		_ssr.SetGlobal(_ptrPins[i], !_anodeRow);
	}

	_ssr.Push();
}

void LedMatrix::Fill() {	
	//Цикл по пинам столбцов
	for(int i = 0; i < _colCount; i++) {
		_ssr.SetGlobal(_ptrPins[i], !_anodeRow);
	}

	//Цикл по пинам строк
	for(int i = _colCount; i < _colCount + _rowCount; i++) {
		_ssr.SetGlobal(_ptrPins[i], _anodeRow);
	}

	_ssr.Push();
}
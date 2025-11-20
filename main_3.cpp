#include <iostream>

// Завдання
void task_if32();
void task_if20();
void task_geom12();
int main() {
	int menu;
	std::cout << "Task number (32, 20, or 2 for geom 12): ";
	std::cin >> menu;
	switch(menu) {
		case 32:
			task_if32();
			break;
		case 20:
			task_if20();
			break;
		case 2:
			task_geom12();
			break;
		default:
			std::cout << "Wrong task number! (Only 32, 20, 2)" << std::endl;
	}
	return 0;
}
// ===================== If32 =====================
void task_if32() {
	std::cout << "************* If 32 *****************" << std::endl;
	// 1. Оголошуємо змінні: 'x' - дійсне, 'h' - ціле
	double x;
	int h;
	// 2. Вхідні дані
	std::cout << "Введіть дійсне число x: ";
	std::cin >> x;
	// 3. Алгоритм з розгалуженням (if / else if / else)
	if(x < 0) {
		// Перша строка: x < 0
		h = 2 * x; // Якщо x = -1.5, h буде -3 (int)
	} else if(x < 3) {
		// Друга строка: 0 <= x < 3
		h = x; // Якщо x = 2.8, h буде 2 (int)
	} else {
		// Третя строка: x >= 3
		h = 6 - x; // Якщо x = 4.5, h буде 1 (int)
	}
	// 4. Вивод результату
	std::cout << "Значення функції h = " << h << std::endl;
}
// ===================== If20 =====================
void task_if20() {
	std::cout << "************* If 20 *****************" << std::endl;
	// 1. Отримуєм дані
	// Оголошуємо змінні
	double a, b, c;
	std::cout << "Введіть координати трьох точок (A, B, C): ";
	// Ввід
	std::cin >> a >> b >> c;
	// 2. Алгоритм з розгалуженням (if/else)
	// Порівнюємо відстань
	if(std::abs(b - a) < std::abs(c - a)) {
		// Якщо відстань до B (abs(b-a)) строго менша
		std::cout << "Точка: B" << std::endl;
		std::cout << "Відстань: " << std::abs(b - a) << std::endl;
	} else {
		// В усіх інших випадках (C ближче АБО відстані однакові)
		std::cout << "Точка: C" << std::endl;
		std::cout << "Відстань: " << std::abs(c - a) << std::endl;
	}
}
// ===================== Geom12 =====================
void task_geom12() {
	std::cout << "************* Geometry (variant 12) *****************" << std::endl;
	double x, y, r;
	std::cout << "Enter radius r: ";
	std::cin >> r;
	std::cout << "Enter coordinates x, y: ";
	std::cin >> x >> y;
	// Перевірка вводу.
	if(!std::cin || r <= 0) {
		std::cout << "Invalid input!" << std::endl;
		// Очистити потік вводу
		std::cin.clear();
		// Проігнорувати решту неправильного вводу
		std::cin.ignore(10000, '\n');
		return;
	}
	// 1) Перевірка для верхнього-правого сектора (І квадрант)
	double dx1 = x - r;
	double dy1 = y - r;
	bool inCircle1 = (dx1 * dx1 + dy1 * dy1) <= (r * r); // Перевірка належності колу
	bool isYellow1 = inCircle1 && (x >= 0) && (y >= x); // Перевірка обмежень сектора
	// 2) Перевірка для нижнього-лівого сектора (ІІІ квадрант)
	double dx2 = x + r;
	double dy2 = y + r;
	bool inCircle2 = (dx2 * dx2 + dy2 * dy2) <= (r * r); // Перевірка належності колу
	bool isYellow2 = inCircle2 && (y <= 0) && (y >= x); // Перевірка обмежень сектора
	// Точка належить, якщо вона потрапляє в ПЕРШИЙ АБО ДРУГИЙ жовтий сектор
	if(isYellow1 || isYellow2) {
		std::cout << "Точка належить жовтій області (var.12)." << std::endl;
	} else {
		std::cout << "Точка НЕ належить жовтій області (var.12)." << std::endl;
	}
}
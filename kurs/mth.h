#pragma once

//Глобальные переменные пересчёта положения
double omega, alpha, amplitude, phinull, length, mtime, massa, gamma, beta = 0.0, alphamax, w0, lencheck, percheck, gx, gy, logdeck, pi;
//Глобальные переменные таймера
double seconds, minutes, hourses, milis;
//Начальные значения углов, дискрет по времени, скорость свободного падения
const auto Dtime = 0.005, g = 9.81, alpha0 = 0.0, omega0 = 10.0;
//Флаг проверки
bool endcheck;
int gfh;
//Флаги для проверки правильности выполнения теста
bool q1f, q2f, q3f, q4f;
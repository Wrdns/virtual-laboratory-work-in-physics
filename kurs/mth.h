#pragma once

//���������� ���������� ��������� ���������
double omega, alpha, amplitude, phinull, length, mtime, massa, gamma, beta = 0.0, alphamax, w0, lencheck, percheck, gx, gy, logdeck, pi;
//���������� ���������� �������
double seconds, minutes, hourses, milis;
//��������� �������� �����, ������� �� �������, �������� ���������� �������
const auto Dtime = 0.005, g = 9.81, alpha0 = 0.0, omega0 = 10.0;
//���� ��������
bool endcheck;
int gfh;
//����� ��� �������� ������������ ���������� �����
bool q1f, q2f, q3f, q4f;
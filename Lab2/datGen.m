fs = 1000;
f = 10;
nCycles = 2;
t = 0:1/fs:nCycles/f;
x = sawtooth(2*pi*t*f, 1/2)*2^15;
y = int16(x);
y = y';
dlmwrite("triangle2.dat", y);
% plot(t, y);
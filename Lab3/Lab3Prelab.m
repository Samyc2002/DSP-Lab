Lh = 3001;
n = 1:Lh;
start = 0;
End = 0;
if rem(Lh, 2) == 1
    start = (Lh-1)/4;
    End = 3*(Lh-1)/4;
else
    start = (Lh)/4;
    End = 1+3*(Lh)/4;
end
h = zeros(1, Lh);
for i=start:End
    h(i) = 1;
end

Lx = 3001;
n = 1:Lx;
x = zeros(1, Lx);
x(floor(Lx/2)) = 1;

convolve = convolution(x, h);
c_convolve = circular_convolution(x, h);
nconv = 1:length(convolve);
ncconv = 1:length(c_convolve);

figure();
subplot(2,1,1);
plot(nconv, convolve); %  EXERCISE: Plot Magnitude  of V
title('Convolution')

subplot(2,1,2); 
plot(ncconv, c_convolve); %  EXERCISE: Plot Magnitude  of V
title('Circular Convolution')

function y = convolution(x, h)
    m = length(x);
    n = length(h);
    X=[x, zeros(1, n)];
    H=[h, zeros(1, m)];
    for i=1:m+n-1
        y(i)=0;
        for j=1:m
            if(i-j+1>0)
                y(i)=y(i)+X(j)*H(i-j+1);
            end
        end
    end
end

function y = circular_convolution(x, h)
    Lx = length(x);
    Lh = length(h);
    N = Lx+Lh-1;
    xpad = [x zeros(1,Lh)];
    hpad = [h zeros(1,Lx)];
    y = ifft(fft(xpad).*fft(hpad));
    y = y(1:N);
end
function interpola(f,a,b,n)
% Approssimazione di una funzione mediante polinomio interpolante
% Dati di input
%     f: funzione da interpolare
% [a,b]: intervallo di rappresentazione
%     n: numero di nodi equidistanti

if nargin==0
    esempio=2;
    switch esempio
        case 1
            % Esempio 1
            f=@(x)(sin(x));
            a=0;
            b=pi;
            n=3;
        case 2
            % Esempio 2
            f=@(x)(exp(-x).*cos(x));
            a=0;
            b=2*pi;
            n=10;
        case 3
            % Esempio 3 (funzione di Runge)
            f=@(x)(1./(x.^2+1));
            a=-5;
            b=5;
            n=15;

    end
end

x=linspace(a,b,n); % nodi
y=f(x); % valutazione della funzione f nei nodi
X=linspace(a,b,100)';
pX=lagrange(x,y,X);
fX=f(X);


% parte grafica
figure(1)
plot(x,y,'o',X,fX,X,pX,'g')
legend('punti','f(x)','p_n(x)')
set(gca,'fontsize',24)
title('Interpolazione polinomiale')


function Y=lagrange(x,y,X)
% Interpolazione di Lagrange
% sintassi: Y=lagrange(x,y,X)
%
% Parametri di input
% x: vettore dei nodi
% y: vettore delle ordinate
% X: vettore di punti in cui valutare il polinomio interpolante
% 
% Parametri di output
% Y: vettore delle valutazioni del polinomio interpolante nei punti in X

n=length(x);
m=length(X);
Y=zeros(m,1);

for j=1:m
    for k=1:n
        % calcolo Lk(X(j))
        Lk=1;
        for i=[1:k-1,k+1:n]
            Lk=Lk*(X(j)-x(i))/(x(k)-x(i));
        end
        Y(j)=Y(j)+Lk*y(k);
    end
end

  
function x=triang_sup(A,b)
%    Algoritmo di sostituzione all'indietro
%    per la risoluzione dei sistemi lineari
%   triangolari superiori
%
%    INPUT
%    A: matrice dei coefficienti triangolare superiore
%    b: vettore dei termini noti
%    
%    OUTPUT
%    x: vettore soluzione del sistema Ax=b
[~,n]=size(A);% oppure n=length(b)
x=zeros(n,1);% preallochiamo la memoria per x
tol=1e-15;
for i=n:-1:1
    if abs(A(i,i))<tol
        error('matrice singolare')
    else
        somma=0;
        for j=i+1:n
            somma=somma+A(i,j)*x(j);
        end
        x(i)=(b(i)-somma)/A(i,i);
    end
end
        
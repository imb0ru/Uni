function [L,U]=fattlu(A)
% Fattorizzazione LU di una matrice quadrata
% 
% sintassi: [L,U]=fattlu(A)
%
% Dati di input
% A: matrice quadrata da fattorizzare
%
% Dati di output
% L: matrice triangolare inferiore speciale
% U: matrice triangolare superiore
%    tali che A=L*U

[~,n]=size(A);
tol=1e-14;
L=eye(n);
for k=1:n-1
    for i=k+1:n
        if abs(A(k,k))<tol
            error('minore principale di testa nullo')
        end
        mik=-A(i,k)/A(k,k);
        for j=k+1:n
            A(i,j)=A(i,j)+mik*A(k,j);
        end
        L(i,k)=-mik;
    end
end
U=triu(A);


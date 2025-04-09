function [alpha,it]=bisezioni(f,a,b,tol,itmax)
% METODO DELLE SUCCESSIVE BISEZIONI
%
% sintassi: [alpha,it]=bisezioni(f,a,b,tol)
% 
% parametri di input
%   f: funzione di cui calcolare uno zero
% a,b: estremi dell'intervallo di lavor
% tol: precisione richiesta
% itmax: numero massimo di iterate consentite 
%
% parametri di output
% alpha: approssimazione di uno zero di f
%    it: iterazioni effettuate dal metodo
%
% Autore: Felice Iavernaro
%   data: 29/09/2021

fa=f(a);
fb=f(b);
if fa*fb>0
    error('La funzione non cambia segno agli estremi')
end

it=0;
arresto=0;
while not(arresto) && it<=itmax
    it=it+1;
    c=(a+b)/2; % punto medio tra a e b
    fc=f(c);
    if fa*fc<0
        b=c;
    else
        a=c;
        fa=fc;
    end
    arresto=b-a<tol;
end

if not(arresto)
    warning('precisone richesta non raggiunta')
end
alpha=c;
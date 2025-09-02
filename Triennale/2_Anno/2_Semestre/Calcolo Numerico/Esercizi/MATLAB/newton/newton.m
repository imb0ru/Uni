function [alpha,it]=newton(f,x0,tol,itmax)
% METODO DI NEWTON
%
% sintassi: [alpha,it]=newton(f,x0,tol,itmax)
% 
% parametri di input
%     f: funzione di cui calcolare uno zero
%    x0: stima iniziale dello zero alpha di f
%   tol: precisione richiesta
% itmax: numero massimo di iterate consentite 
%
% parametri di output
% alpha: approssimazione di uno zero di f
%    it: iterazioni effettuate dal metodo
%
% Autore: Felice Iavernaro
%   data: 13/10/2021

arresto=0;
it=0;
while ~arresto && it<itmax
    it=it+1;
    x1=x0-f(x0)/f(x0,1);
    arresto=abs(x1-x0)<tol; % criterio di arresto sull'errore assoluto
    x0=x1;
end

if not(arresto)
    warning('precisone richesta non raggiunta')
end
alpha=x1;
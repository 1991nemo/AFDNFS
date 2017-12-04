%=========================================================================%
%                  Sharif University of Technology                        %
%                  Aerospace Engineering Department                       %
%                    Flight Dynamics and Control                          %
%-------------------------------------------------------------------------%
% Written by:                   Amir H. Khodabakhsh,                      %
% Student Code:                 93208448                                  %
% Date:                         Octrober, 2014                            %
%=========================================================================%
%                   Avanced Flight Dynamics  (AFD)                        %
%                   Beech 99 Aerodynamical Database                       %
%-------------------------------------------------------------------------%
%                               AFDNFS                                    %
%=========================================================================%
function nfs=TransferFunction(varargin)
if (nargin==0||nargin==2)~=1
    error('TransferFunction:argChk','Wrong number of arguments.');
end;
if nargin==2
    plt=varargin{2};
else
    plt='false';
end;
% clc; clear all; close all;
%% General
nfs=PlaneData('SI');
% nfs=PlaneData('Imperial');
% q                       =   nfs.dynamicpressure             ;
% q                       =   nfs.q                           ;
% c                       =   nfs.meanchord                   ;
% m                       =   nfs.mass                        ;
% Iyy                     =   nfs.I(2,2)                      ;
% b                       =   nfs.span                        ;
s           =   nfs.refarea                     ;
u           =   nfs.crusevel                    ;
Ixx         =   nfs.I(1,1)                      ;
Izz         =   nfs.I(3,3)                      ;
Ixz         =   nfs.I(1,3)                      ;
ae          =   nfs.aero                        ;
g           =   nfs.gravityaccel                ;
theta1      =   nfs.attitude0(2)                ;
A           =   Ixz/Ixx                         ;
B           =   Ixz/Izz                         ;
Mubar       =   ae.Mu+ae.Mwdot*ae.Zu            ;
Mwbar       =   ae.Mw+ae.Mwdot*ae.Zw            ;
Mqbar       =   ae.Mq+u*ae.Mwdot                ;
Mthetabar   =   -g*ae.Mw*sin(nfs.pathangle)     ;
Mdelta_ebar =   ae.Mdelta_e+ae.Mwdot*ae.Zdelta_e;
syms s;
% Transfer Function Matrix -----------------------------------------------%

nfs.dyn.long.A  =   [s-ae.Xu-ae.XTu,-ae.Xalpha,g*cos(theta1);
                    -ae.Zu,s*(u-ae.Zalphadot)-ae.Zalpha,-(ae.Zq+u)*s+g*sin(theta1);
                    -(ae.Mu+ae.MTu),-(ae.Malphadot*s+ae.Malpha+ae.MTalpha),s^2-ae.Mq*s];
                
nfs.dyn.lat.A   =   [s*u-ae.Ybeta,          -(s*ae.Yp+g*cos(theta1)),   s*(u-ae.Yr);
                     -ae.Lbeta,             s^2-ae.Lp*s,                -(s^2*A+s*ae.Lr);
                     -(ae.Nbeta+ae.NTbeta), -(s^2*B+ae.Np*s),           s^2-s*ae.Nr];

% ref: McLean; Xu in maclean = Xu+XTu in Roskam
% ref: McLean; U0 in McLean -> U0+zq in Roskam
% ref: McLean; No Moment Derivative for thrust in McLean -> MTu & MTalpha
% in Roskam has been added to the code in accordance; MTalpha = U0*MTw
%                   u       w       q       theta       
Amatlong       =   [ae.Xu+ae.XTu    ae.Xw                   0       -g*cos(nfs.pathangle);
                    ae.Zu           ae.Zw                   u+ae.Zq	-g*sin(nfs.pathangle);
                    Mubar+ae.MTu	Mwbar+ae.MTalpha/u      Mqbar   Mthetabar            ;
                    0               0                       1       0                    ;];

% % % % % % There is an  issue with Amatlat (v variant) - the results are not correct!

%                   v           p           r                   phi                     psi    
Amatlat        =   [ae.Yv       0           u                   -g*cos(nfs.pathangle)   0;
                    ae.Lvprime  ae.Lpprime  ae.Lrprime          0                       0;
                    ae.Nvprime  ae.Npprime  ae.Nrprime          0                       0;
                    0           1           tan(nfs.pathangle)  0                       0;
                    0           0           sec(nfs.pathangle)  0                       0;];

%                   beta        p           r                   phi                     psi    
% Amatlat        =   [ae.Ybeta       0           -1                  g/u                     0;
%                     ae.Lbetaprime  ae.Lpprime  ae.Lrprime          0                       0;
%                     ae.Nbetaprime  ae.Npprime  ae.Nrprime          0                       0;
%                     0           1           tan(nfs.pathangle)  0                       0;
%                     0           0           sec(nfs.pathangle)  0                       0;];
%                   delta_e
Bmatlong       =   [ae.Xdelta_e;
                    ae.Zdelta_e;
                    Mdelta_ebar;
                    0          ;];
%                   delta_a             delta_r
Bmatlat        =   [ae.Ydelta_a         ae.Ydelta_r     ;
                    ae.Ldelta_aprime    ae.Ldelta_rprime;
                    ae.Ndelta_aprime    ae.Ndelta_rprime;
                    0                   0               ;
                    0                   0               ;];

Amat            =   blkdiag(Amatlong,Amatlat);
Bmat            =   blkdiag(Bmatlong,Bmatlat);
Cmat            =   eye(size(Amat));
Dmat            =   0;
nfs.dyn.linsys  =   ss(Amat,Bmat,Cmat,Dmat,0,'StateName',{'U','W','Q',...
    'Theta','V','P','R','Phi','Psi'},'InputName',{'de','da','dr'},...
    'OutputName',{'U','W','Q','Theta','V','P','R','Phi','Psi'});
% reorder the linear system to the convenient form
p = [1, 5, 2, 6, 3, 7, 8, 4, 9];


longsys         =   ss(Amatlong,Bmatlong,eye(size(Amatlong)),0,...
    'StateName',{'U','W','Q','Theta'},'InputName',{'de'},...
    'OutputName',{'U','W','Q','Theta'});
% latsys          =   ss(Amatlat,Bmatlat,eye(size(Amatlat)),zeros(5,2),...
%     'StateName',{'V','P','R','Phi','Psi'},'InputName',{'da','dr'},...
%     'OutputName',{'V','P','R','Phi','Psi'});

latsys          =   ss(Amatlat,Bmatlat,eye(size(Amatlat)),zeros(5,2),...
    'StateName',{'Beta','P','R','Phi','Psi'},'InputName',{'da','dr'},...
    'OutputName',{'Beta','P','R','Phi','Psi'});

clear q s c u m b Ixx Iyy Izz Ixz ae coeff rho s g theta1 A B Mubar Mwbar ...
      Mqbar Mthetabar Mdelta_ebar;

% Characteristic Equation ------------------------------------------------%
nfs.dyn.long.ss      =   longsys                                  ;
nfs.dyn.long.tf      =   tf(nfs.dyn.long.ss)                      ;
[nfs.dyn.long.wn,...
 nfs.dyn.long.zeta]...
                     =   damp(nfs.dyn.long.tf)                    ;
[z,p,k]              =   zpkdata(nfs.dyn.long.tf)                 ;
nfs.dyn.long.zero    =   z                                        ;
nfs.dyn.long.pole    =   p{end}                                   ;
nfs.dyn.long.gain    =   k                                        ;
nfs.dyn.long.wn      =   unique(nfs.dyn.long.wn)                  ;
nfs.dyn.long.zeta    =   unique(nfs.dyn.long.zeta)                ;
nfs.dyn.long.cheq    =   vpa(subs(poly2sym(poly(p{end})),'x','s'),5);

nfs.dyn.lat.ss       =   latsys                                   ;
nfs.dyn.lat.tf       =   tf(nfs.dyn.lat.ss)                       ;
[nfs.dyn.lat.wn,...
 nfs.dyn.lat.zeta]...
                     =   damp(nfs.dyn.lat.tf)                     ;
[z,p,k]              =   zpkdata(nfs.dyn.lat.tf)                  ;
nfs.dyn.lat.zero     =   z                                        ;
nfs.dyn.lat.pole     =   p{end}                                   ;
nfs.dyn.lat.gain     =   k                                        ;
nfs.dyn.lat.wn       =   unique(nfs.dyn.lat.wn)                   ;
nfs.dyn.lat.zeta     =   unique(nfs.dyn.lat.zeta)                 ;
nfs.dyn.lat.cheq     =   vpa(subs(poly2sym(poly(p{end})),'x','s'),5);

nfs.dyn.long.correct.cheq = det(nfs.dyn.long.A);
nfs.dyn.long.correct.pole = double(solve(nfs.dyn.long.cheq));
[nfs.dyn.long.correct.wn, nfs.dyn.long.correct.zeta]...
                     =   damp(zpk([],nfs.dyn.long.correct.pole,1));
nfs.dyn.long.correct.wn       =   unique(nfs.dyn.long.correct.wn);
nfs.dyn.long.correct.zeta     =   unique(nfs.dyn.long.correct.zeta);

nfs.dyn.lat.correct.cheq = det(nfs.dyn.lat.A);
nfs.dyn.lat.correct.pole = double(solve(nfs.dyn.lat.correct.cheq));
[nfs.dyn.lat.correct.wn, nfs.dyn.lat.correct.zeta]...
                     =   damp(zpk([],nfs.dyn.lat.correct.pole,1));
nfs.dyn.lat.correct.wn       =   unique(nfs.dyn.lat.correct.wn);
nfs.dyn.lat.correct.zeta     =   unique(nfs.dyn.lat.correct.zeta);




%{
% omega                =   unique(abs(nfs.dyn.long.pol))            ;
% nfs.dyn.long.omega_p =   max(omega)                               ;
% nfs.dyn.long.omega_s =   min(omega)                               ;
% zeta                 =   unique(-cos(angle((nfs.dyn.longpol))))   ;
%}

if strcmp(plt,'true')
    disp('Longitudinal');
    routh(sym2poly(det(nfs.dyn.long.A)));
    disp('Lateral');
    routh(sym2poly(det(nfs.dyn.lat.A)));
    %

    figure('NumberTitle','off','Name','Longitudinal Poles','Color',[1,1,1]);
    plot(-10:10,zeros(size(-10:10)),':k',zeros(size(-10:10)),-10:10,':k');
    hold on; plot(nfs.dyn.long.correct.pole,'o');
    xlabel('Re'); ylabel('Im');
    title('Longitudinal Characteristic Equation Poles');
    axis([(min(real(nfs.dyn.long.correct.pole)))-1, (max(real(nfs.dyn.long.correct.pole)))+1,...
          1.1*(min(imag(nfs.dyn.long.correct.pole))), 1.1*(max(imag(nfs.dyn.long.correct.pole)))]);
    figure('NumberTitle','off','Name','Lateral Poles','Color',[1,1,1]);
    plot(-10:10,zeros(size(-10:10)),':k',zeros(size(-10:10)),-10:10,':k');
    hold on; plot(nfs.dyn.lat.correct.pole,'o');
    xlabel('Re'); ylabel('Im');
    title('Lateral Characteristic Equation Poles');
    axis([(min(real(nfs.dyn.lat.correct.pole)))-1, (max(real(nfs.dyn.lat.correct.pole)))+1,...
          1.1*(min(imag(nfs.dyn.lat.correct.pole))), 1.1*(max(imag(nfs.dyn.lat.correct.pole)))]);
end;
%}























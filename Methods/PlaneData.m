%=========================================================================%
%                  Sharif University of Technology                        %
%                  Aerospace Engineering Department                       %
%                    Flight Dynamics and Control                          %
%-------------------------------------------------------------------------%
% Written by:                   Amir H. Khodabakhsh,                      %
% Student Code:                 93208448                                  %
% Date:                         October, 2014                             %
%=========================================================================%
%                     Advanced Flight Dynamics (AFD)                      %
%                    Non-linear Flight Simulator (NFS)                    %
%-------------------------------------------------------------------------%
%                               PlaneData                                 %
%=========================================================================%
function nfs=PlaneData(unit)
% 
if ~strcmp('SI',unit)
    warning('The simulation has been verified only for SI inputs');
end;
nfs.unit = unit;
str = pwd; str = str(1:end-8);
excelFile = [str '\NFSData\NFS Data.xlsx'];
[~,unit,~]=xlsread(excelFile,1);
nfs.inputunit = unit{10,3};

if ((strcmp(nfs.unit,'Imperial')~=1)||(strcmp(nfs.unit,'SI')~=1))>1
    error('ERROR');
end;
data=xlsread(excelFile,2);
nfs.weight          =   data(1,1);                  %lbs        || N
nfs.altitude        =   data(2,1);                  %ft         || m
nfs.meanchord       =   data(3,1);                  %ft         || m
nfs.span            =   data(4,1);                  %ft         || m
nfs.refarea         =   data(5,1);                  %ft^2       || m^2
nfs.crusevel        =   data(6,1);                  %ft/sec     || m/s
nfs.q               =   data(7,1);                  %lbs/ft^2	|| Pa
nfs.dynamicpressure =   data(7,1);                  %lbs/ft^2   || Pa
nfs.pathangle       =   data(8,1);                  %rad        || rad            //gamma
nfs.tdis            =   data(9,1);                  %ft         || m             //dt
nfs.tmisalign       =   data(10,1);                 %rad        || rad            //phi_T
nfs.iH0             =   data(11,1);                 %rad        || rad       
nfs.consumprate     =   data(12,1);                 %lbs/sec	|| kg/s
nfs.gravityaccel    =   data(13,1);                 %ft/s^2     || m/s^2
nfs.I(1,1)          =   data(15,1);                 %slug*ft^2  || 
nfs.I(2,1)          =   data(16,1);                 %slug*ft^2  || 
nfs.I(3,1)          =   data(17,1);                 %slug*ft^2  || 
nfs.I(1,2)          =   data(15,2);                 %slug*ft^2  || 
nfs.I(2,2)          =   data(16,2);                 %slug*ft^2  || 
nfs.I(3,2)          =   data(17,2);                 %slug*ft^2  || 
nfs.I(1,3)          =   data(15,3);                 %slug*ft^2  || 
nfs.I(2,3)          =   data(16,3);                 %slug*ft^2  || 
nfs.I(3,3)          =   data(17,3);                 %slug*ft^2  || 
nfs.Idot(1,1)       =   data(19,1);                 %slug*ft^2  || 
nfs.Idot(2,1)       =   data(20,1);                 %slug*ft^2  || 
nfs.Idot(3,1)       =   data(21,1);                 %slug*ft^2  || 
nfs.Idot(1,2)       =   data(19,2);                 %slug*ft^2  || 
nfs.Idot(2,2)       =   data(20,2);                 %slug*ft^2  || 
nfs.Idot(3,2)       =   data(21,2);                 %slug*ft^2  || 
nfs.Idot(1,3)       =   data(19,3);                 %slug*ft^2  || 
nfs.Idot(2,3)       =   data(20,3);                 %slug*ft^2  || 
nfs.Idot(3,3)       =   data(21,3);                 %slug*ft^2  || 
nfs.attitude0       =   data(23,:)';                %rad        || 
nfs.angularvel0     =   data(25,:)';                %rad/sec    || 

nfs.mass            =   nfs.weight/nfs.gravityaccel;
nfs.AR              =   (nfs.span^2)/nfs.refarea;
%-------------------------------------------------------------------------%
if ~strcmp(nfs.unit,nfs.inputunit)
    if strcmp(nfs.inputunit,'Imperial')
        nfs.mass            =   nfs.weight*0.453592;        %kg
        nfs.gravityaccel    =   9.8067;                     %m/s^2
        nfs.weight          =   nfs.mass*nfs.gravityaccel;  %N
        nfs.altitude        =   nfs.altitude*0.3048;        %m
        nfs.meanchord       =   nfs.meanchord*0.3048;       %m
        nfs.refarea         =   nfs.refarea*(0.3048).^2;    %m^2
        nfs.crusevel        =   nfs.crusevel*0.3048;        %m/s
        [~, ~, ~, rho]      =   atmoscoesa(nfs.altitude);   %kg/m^3
        nfs.dynamicpressure =   0.5*rho*nfs.crusevel(1).^2; %Pa
        nfs.q               =   nfs.q*47.8802;              %Pa
        nfs.xcg             =   0.33*nfs.meanchord;         %m
        nfs.I               =   nfs.I.*1.355817962;         %kg*m^2
        nfs.tdis            =   nfs.tdis*0.3048;            %m
        nfs.span            =   nfs.span*0.3048;            %m
        nfs.consumprate     =   nfs.consumprate*...
                                0.453592*nfs.gravityaccel;  %kg/s
    elseif strcmp(nfs.inputunit,'SI')
        % well! everything should express in Imperial units
    end;
end;
if strcmp(nfs.unit,nfs.inputunit)
    if strcmp(nfs.inputunit,'Imperial')
        % well! it's ok
    elseif strcmp(nfs.inputunit,'SI')
        [~, ~, ~, rho]      =   atmoscoesa(nfs.altitude);   %kg/m^3
        nfs.dynamicpressure =   0.5*rho*nfs.crusevel(1).^2;
        nfs.xcg             =   0.33*nfs.meanchord;         %m 
    end;
end;
nfs.initialpos      =   [0 0 -nfs.altitude]';
% Aerodynamics ===========================================================%
nfs.aero.e              =   0.85                        ;
nfs.aero.k              =   0;%1/(pi*nfs.aero.e*nfs.AR)    ;
%% Dimentionless Derivatives
clear data;
data=xlsread(excelFile,3);
% Stability Derivatives --------------------------------------------------%
%           Longitudinal
nfs.aero.cD1            =   data(1) ;
nfs.aero.cD0            =   data(2) ;
nfs.aero.cDu            =   data(3) ;
nfs.aero.cDalpha        =   data(4) ;
nfs.aero.cDM            =   data(5) ;
nfs.aero.cTx1           =   data(6) ;
nfs.aero.cTxu           =   data(7) ;
nfs.aero.cL1            =   data(8) ;
nfs.aero.cL0            =   data(9) ;
nfs.aero.cLu            =   data(10);
nfs.aero.cLalpha        =   data(11);
nfs.aero.cLalphadot     =   data(12);
nfs.aero.cLq            =   data(13);
nfs.aero.cLM            =   data(14);
nfs.aero.cm1            =   data(15);
nfs.aero.cm0            =   data(16);
nfs.aero.cmu            =   data(17);
nfs.aero.cmalpha        =   data(18);
nfs.aero.cmalphadot     =   data(19);
nfs.aero.cmq            =   data(20);
nfs.aero.cmT1           =   data(21);
nfs.aero.cmTu           =   data(22);
nfs.aero.cmTalpha       =   data(23);
nfs.aero.cmM            =   data(24);
%        Lateral-Directional
nfs.aero.cYbeta         =   data(26);
nfs.aero.cYbetadot      =   data(27);
nfs.aero.cYp            =   data(28);
nfs.aero.cYr            =   data(29);
nfs.aero.clbeta         =   data(30);
nfs.aero.clbetadot      =   data(31);
nfs.aero.clp            =   data(32);
nfs.aero.clr            =   data(33);
nfs.aero.cnbeta         =   data(34);
nfs.aero.cnbetadot      =   data(35);
nfs.aero.cnp            =   data(36);
nfs.aero.cnr            =   data(37);
nfs.aero.cnTbeta        =   data(38);

% Control Derivatives ----------------------------------------------------%
% Longitudinal
nfs.aero.cDdelta_e      =   data(42);   %1/rad
nfs.aero.cDdelta_f      =   data(43);   %1/rad
nfs.aero.cDdelta_a      =   data(44);   %1/rad
nfs.aero.cDdelta_r      =   data(45);   %1/rad
nfs.aero.cLdelta_e      =   data(46);   %1/rad
nfs.aero.cLdelta_f      =   data(47);   %1/rad
nfs.aero.cmdelta_e      =   data(48);   %1/rad
nfs.aero.cmdelta_f      =   data(49);   %1/rad
nfs.aero.cDiH           =   data(50);   %1/rad
nfs.aero.cLiH           =   data(51);   %1/rad
nfs.aero.cMiH           =   data(52);   %1/rad
%Lateral-Directional
nfs.aero.cYdelta_a      =   data(54);
nfs.aero.cYdelta_r      =   data(55);
nfs.aero.cldelta_a      =   data(56);
nfs.aero.cldelta_r      =   data(57);
nfs.aero.cndelta_a      =   data(58);
nfs.aero.cndelta_r      =   data(59);
%% Dimentional Derivatives
q                       =   nfs.dynamicpressure             ;
s                       =   nfs.refarea                     ;
c                       =   nfs.meanchord                   ;
u                       =   nfs.crusevel                    ;
m                       =   nfs.mass                        ;
Ixx                     =   nfs.I(1,1)                      ;
Iyy                     =   nfs.I(2,2)                      ;
Izz                     =   nfs.I(3,3)                      ;
Ixz                     =   nfs.I(1,3)                      ;
ae                      =   nfs.aero                        ;
b                       =   nfs.span                        ;

% Longitudinal -----------------------------------------------------------%
coeff                   =   q*s/m                           ;
nfs.aero.Xu             =   -(coeff*(ae.cDu+2*ae.cD1))/u    ;
nfs.aero.XTu            =   coeff*(ae.cTxu+2*ae.cTx1)/u     ;
nfs.aero.Xalpha         =   -coeff*(ae.cDalpha-ae.cL1)      ;
nfs.aero.Xw             =   nfs.aero.Xalpha/u               ;
nfs.aero.Xdelta_e       =   -coeff*ae.cDdelta_e             ;
nfs.aero.Zu             =   -coeff*(ae.cLu+2*ae.cL1)/u      ;
nfs.aero.Zalpha         =   -coeff*(ae.cLalpha+ae.cD1)      ;
nfs.aero.Zw             =   nfs.aero.Zalpha/u               ;
nfs.aero.Zalphadot      =   -coeff*c*ae.cLalphadot/(2*u)    ;
nfs.aero.Zwdot          =   nfs.aero.Zalphadot/u            ;
nfs.aero.Zq             =   -coeff*c*ae.cLq/(2*u)           ;
nfs.aero.Zdelta_e       =   -coeff*ae.cLdelta_e             ;

coeff                   =   q*s*c/Iyy                       ;
nfs.aero.Mu             =   coeff*(ae.cmu+2*ae.cm1)/u       ;
nfs.aero.MTu            =   coeff*(ae.cmTu+2*ae.cmT1)/u     ;
nfs.aero.Malpha         =   coeff*ae.cmalpha                ;
nfs.aero.Mw             =   nfs.aero.Malpha/u               ;
nfs.aero.MTalpha        =   coeff*ae.cmTalpha               ;
nfs.aero.Malphadot      =   coeff*c*ae.cmalphadot/(2*u)     ;
nfs.aero.Mwdot          =   nfs.aero.Malphadot/u            ;
nfs.aero.Mq             =   coeff*c*ae.cmq/(2*u)            ;
nfs.aero.Mdelta_e       =   coeff*ae.cmdelta_e              ;

% Lateral-Directional ----------------------------------------------------%
coeff                   =   q*s/m                           ;
nfs.aero.Ybeta          =   coeff*ae.cYbeta                 ;
nfs.aero.Yv             =   nfs.aero.Ybeta/u                ; % for small Beta
nfs.aero.Yp             =   coeff*b*ae.cYp/(2*u)            ;
nfs.aero.Yr             =   coeff*b*ae.cYr/(2*u)            ;
nfs.aero.Ydelta_a       =   coeff*ae.cYdelta_a              ;
nfs.aero.Ydelta_r       =   coeff*ae.cYdelta_r              ;

coeff                   =   q*s*b/Ixx                       ;
nfs.aero.Lbeta          =   coeff*ae.clbeta                 ;
nfs.aero.Lv             =   nfs.aero.Lbeta/u                ;
nfs.aero.Lp             =   coeff*b*ae.clp/(2*u)            ;
nfs.aero.Lr             =   coeff*b*ae.clr/(2*u)            ;
nfs.aero.Ldelta_a       =   coeff*ae.cldelta_a              ;
nfs.aero.Ldelta_r       =   coeff*ae.cldelta_r              ;

coeff                   =   q*s*b/Izz                       ;
nfs.aero.Nbeta          =   coeff*ae.cnbeta                 ;
nfs.aero.Nv             =   nfs.aero.Nbeta/u                ;
nfs.aero.NTbeta         =   coeff*ae.cnTbeta                ;
nfs.aero.Nbetadot       =   coeff*b*ae.cnbetadot/(2*u);
nfs.aero.Np             =   coeff*b*ae.cnp/(2*u)            ;
nfs.aero.Nr             =   coeff*b*ae.cnr/(2*u)            ;
nfs.aero.Ndelta_a       =   coeff*ae.cndelta_a              ;
nfs.aero.Ndelta_r       =   coeff*ae.cndelta_r              ;

IA                      =   Ixz/Ixx                         ;
IB                      =   Ixz/Izz                         ;
Lda                     =   nfs.aero.Ldelta_a               ;
Nda                     =   nfs.aero.Ndelta_a               ;
Ldr                     =   nfs.aero.Ldelta_r               ;
Ndr                     =   nfs.aero.Ndelta_r               ;

nfs.aero.Lbetaprime     =   nfs.aero.Lbeta+IB*nfs.aero.Nbeta;
nfs.aero.Lvprime        =   nfs.aero.Lv+IB*nfs.aero.Nv      ;
nfs.aero.Lpprime        =   nfs.aero.Lp+IB*nfs.aero.Np      ;
nfs.aero.Lrprime        =   nfs.aero.Lr+IB*nfs.aero.Nr      ;
nfs.aero.Ldelta_aprime  =   Lda+IB*Nda                      ;
nfs.aero.Ldelta_rprime  =   Ldr+IB*Ndr                      ;
nfs.aero.Nbetaprime     =   nfs.aero.Nbeta+IA*nfs.aero.Lbeta;
nfs.aero.Nvprime        =   nfs.aero.Nv+IA*nfs.aero.Lv      ;
nfs.aero.Npprime        =   nfs.aero.Np+IA*nfs.aero.Lp      ;
nfs.aero.Nrprime        =   nfs.aero.Nr+IA*nfs.aero.Lr      ;
nfs.aero.Ndelta_aprime  =   Nda+IA*Lda                      ;
nfs.aero.Ndelta_rprime  =   Ndr+IA*Ldr                      ;
% ae = nfs.aero;
% nfs.aero.Mubar          =   ae.Mu+ae.Mwdot*ae.Zu            ;
% nfs.aero.Mwbar          =   ae.Mw+ae.Mwdot*ae.Zw            ;
% nfs.aero.Mqbar          =   ae.Mq+u*ae.Mwdot                ;
% nfs.aero.Mthetabar      =   -g*ae.Mw*sin(nfs.pathangle)     ;
% nfs.aero.Mdelta_ebar    =   ae.Mdelta_e+ae.Mwdot*ae.Zdelta_e;



clear Lda Nda IA IB q s c u m b Ixx Iyy Izz Ixz ae coeff rho;

























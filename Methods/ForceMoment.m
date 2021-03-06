%=========================================================================%
%                  Sharif University of Technology                        %
%                  Aerospace Engineering Department                       %
%                    Flight Dynamics and Control                          %
%-------------------------------------------------------------------------%
% Written by:                   Amir H. Khodabakhsh,                      %
% Student Code:                 93208448                                  %
% Date:                         Octrober, 2014                            %
%=========================================================================%
%                     Avanced Flight Dynamics (AFD)                       %
%                    Nonlinear Flight Simulator (NFS)                     %
%-------------------------------------------------------------------------%
%                               AFDNFS                                    %
%=========================================================================%
function [F_Body,M_Body]=ForceMoment(vel,angularvel,control,attitude,position,thrust,t,nfs)
height=abs(position(3));
p=angularvel(1); q=angularvel(2); r=angularvel(3);
delta_e=control(1);delta_f=control(2);delta_a=control(3);delta_r=control(4);
span=nfs.span; refarea=nfs.refarea; mac=nfs.meanchord;

velmag=VelMag(vel);
[~,rho]=AtmosAttribute(height);
[alpha,beta,~,alphadot,betadot,mach]=AeroAttribute(vel,height,t);
cL=LiftCoeff(nfs.aero,alpha,alphadot,q,delta_e,delta_f,mac,velmag,mach);
cD=DragCoeff(nfs.aero,cL,alpha,delta_f,delta_e,delta_a,delta_r,mach);
cY=SideforceCoeff(nfs.aero,beta,betadot,p,r,delta_a,delta_r,span,velmag);
cl=RollMCoeff(nfs.aero,beta,betadot,p,r,delta_a,delta_r,span,velmag);
cm=PitchMCoeff(nfs.aero,alpha,alphadot,q,delta_f,delta_e,mac,velmag,mach);
cn=YawMCoeff(nfs.aero,beta,betadot,p,r,delta_a,delta_r,span,velmag);
L=LiftForce(cL,rho,velmag,refarea);
D=DragForce(cD,rho,velmag,refarea);
Y=SideForce(cY,rho,velmag,refarea);
l=RollMoment(cl,rho,velmag,refarea,mac);
m=PitchMoment(cm,rho,velmag,refarea,mac);
n=YawMoment(cn,rho,velmag,refarea,mac);
f_aero=AeroForce(L,D,Y);
m_aero=AeroMoment(l,m,n);
T_BW=Wind2Body(alpha,beta);
% f_aero_body=T_BW*f_aero
% thrustvec=[nfs.trim.thrust*cos(nfs.tmisalign),0,nfs.trim.thrust*sin(nfs.tmisalign)]';
thrustvec=[thrust*cos(nfs.tmisalign),0,thrust*sin(nfs.tmisalign)]';
F_Body=BodyForces(f_aero,T_BW,thrustvec,nfs.weight,attitude);
M_Body=BodyMoments(m_aero,T_BW);
end


function velocitymagnitude=VelMag(vel)
    velocitymagnitude=sqrt(dot(vel,vel));
end

function q=DynPres(rho,velmag)
    q=(1/2)*rho*velmag.^2;
end

function [a,rho]=AtmosAttribute(height)
    [~,a,~,rho]=atmosisa(height);
end

function [alpha,beta,dynpres,alphadot,betadot,mach]=AeroAttribute(vel,height,t)
    persistent alphapool betapool timepool alphadotpool betadotpool;
    if isempty(alphapool)||isempty(betapool)||isempty(timepool)
        alphapool=0; betapool=0; timepool=1; alphadotpool=0; betadotpool=0;
    end;
    velmag=VelMag(vel);
    [a,rho]=AtmosAttribute(height);
    mach=velmag/a;
    dynpres=DynPres(rho,velmag);
    alpha=atan(vel(3)/vel(1));
    beta=asin(vel(2)/velmag);
    alphadot=(alpha-alphapool)/(t-timepool);
    if (isnan(alphadot)||isinf(alphadot))
        alphadot=alphadotpool;
    else
        alphadotpool=alphadot;
    end;
    betadot=(beta-betapool)/(t-timepool);
    if (isnan(betadot)||isinf(betadot))
        betadot=betadotpool;
    else
        betadotpool=betadot;
    end;
    alphapool=alpha;
    betapool=beta;
    timepool=t;
end

function cL=LiftCoeff(aerocoef,alpha,alphadot,q,delta_e,delta_f,mac,...
                      velmag,mach)
    nc=mac/(2*velmag);
    
    cL=aerocoef.cL0+aerocoef.cLalpha*alpha+aerocoef.cLalphadot*alphadot*nc+...
        aerocoef.cLq*q*nc+aerocoef.cLdelta_e*delta_e+...
        aerocoef.cLdelta_f*delta_f+aerocoef.cLM*mach ;
end

function cD=DragCoeff(aerocoeff,cL,alpha,delta_f,delta_e,delta_a,delta_r,mach)
    cD=aerocoeff.cD0+aerocoeff.k*cL^2+aerocoeff.cDalpha*abs(alpha)+...
       aerocoeff.cDdelta_f*abs(delta_f)+aerocoeff.cDdelta_e*abs(delta_e)+...
       aerocoeff.cDdelta_a*abs(delta_a)+aerocoeff.cDdelta_r*abs(delta_r)+...
       aerocoeff.cDM*mach;
end

function cY=SideforceCoeff(aerocoeff,beta,betadot,p,r,delta_a,delta_r,span,velmag)
    nc=span/(2*velmag);
    cY=aerocoeff.cYbeta*beta+aerocoeff.cYbetadot*betadot*nc+...
       aerocoeff.cYp*p*nc+aerocoeff.cYr*r*nc+...
       aerocoeff.cYdelta_a*delta_a+aerocoeff.cYdelta_r*delta_r;
end

function cl=RollMCoeff(aerocoeff,beta,betadot,p,r,delta_a,delta_r,span,velmag)
    nc=span/(2*velmag);
    cl=aerocoeff.clbeta*beta+aerocoeff.clbetadot*betadot*nc+...
       aerocoeff.clp*p*nc+aerocoeff.clr*r*nc+aerocoeff.cldelta_a*delta_a+...
       aerocoeff.cldelta_r*delta_r;
end

function cm=PitchMCoeff(aerocoeff,alpha,alphadot,q,delta_f,delta_e,mac,velmag,mach)
    nc=mac/(2*velmag);
    cm=aerocoeff.cm0+aerocoeff.cmalpha*alpha+...
       aerocoeff.cmalphadot*alphadot*nc+aerocoeff.cmq*q*nc+...
       aerocoeff.cmdelta_f*delta_f+aerocoeff.cmdelta_e*delta_e+...
       aerocoeff.cmM*mach;
end

function cn=YawMCoeff(aerocoeff,beta,betadot,p,r,delta_a,delta_r,span,velmag)
    nc=span/(2*velmag);
    cn=aerocoeff.cnbeta*beta+aerocoeff.cnbetadot*betadot+aerocoeff.cnp*p*nc+...
       aerocoeff.cnr*r*nc+aerocoeff.cndelta_a*delta_a+...
       aerocoeff.cndelta_r*delta_r;
end

function L=LiftForce(cL,rho,velmag,refarea)
    L=(1/2)*rho*velmag^2*refarea*cL;
end

function D=DragForce(cD,rho,velmag,refarea)
    D=(1/2)*rho*velmag^2*refarea*cD;
end

function Y=SideForce(cY,rho,velmag,refarea)
    Y=(1/2)*rho*velmag^2*refarea*cY;
end

function l=RollMoment(cl,rho,velmag,refarea,mac)
    l=(1/2)*rho*velmag^2*mac*refarea*cl;
end

function m=PitchMoment(cm,rho,velmag,refarea,mac)
    m=(1/2)*rho*velmag^2*mac*refarea*cm;
end

function n=YawMoment(cn,rho,velmag,refarea,mac)
    n=(1/2)*rho*velmag^2*mac*refarea*cn;
end

function f_aero=AeroForce(L,D,Y)
% In Wind Axis
    f_aero=[-D,Y,-L]';
end

function m_aero=AeroMoment(l,m,n)
%wind axis
    m_aero=[l,m,n]';
end

function T_BW=Wind2Body(alpha,beta)
    T_BW=[cos(alpha),0,-sin(alpha);0,1,0;sin(alpha),0,cos(alpha)]*...
         [cos(beta),-sin(beta),0;sin(beta),cos(beta),0;0,0,1];
    T_BW=T_BW';
end

function F=BodyForces(f_aero,T_BW,thrust,weight,attitude)
    phi=attitude(1); theta=attitude(2);
    W=weight*[-sin(theta),cos(theta)*sin(phi),cos(theta)*cos(phi)]';
    F=T_BW*f_aero+thrust+W;
end

function M=BodyMoments(m_aero,T_BW)
    M=T_BW*m_aero;
end


%=========================================================================%
function [T, a, P, rho] = atmosisa( h )
[T,a,P,rho]=atmoslapse(h,9.76976373083259,1.4,287.0531,0.0065,11000,20000, ...
    1.225,101325,288.15);
end

function [T, a, P, rho] = atmoslapse(h, g, gamma, R, L, hts, htp, rho0, P0, T0 )
if ( h > htp )
    h = htp;
end;
if ( h <  0 )
    h = 0;
end;
if ( h > hts )
    T = T0 - L*hts; 
    expon = exp(g/(R*T)*(hts - h)); 
else
    T = T0 - L*h; 
    expon = 1.0;  
end;
a = sqrt(T*gamma*R);
theta = T/T0;
P = P0*theta.^(g/(L*R)).*expon;
rho=rho0*theta.^((g/(L*R))-1.0).*expon;
end

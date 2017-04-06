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
%                          Trimming Function                              %
%=========================================================================%
function X = AFDTrim(nfs)

x0=[0.0051391149 0.0099074035 568.9885740363];%0];%
options=optimset('Display','iter','TolX',1e-10,'TolFun',1e-30,...
                 'Algorithm','levenberg-marquardt');
[x,~]=fsolve(@(x) TrimCost(x,nfs),x0,options);
disp('------------------------------------------------------------------');
disp('  ');
fprintf('Alpha_trim: %f deg or %6.10f rad\n',rad2deg(x(1)),x(1));
fprintf('DeltaE_trim: %f deg or %6.10f rad\n',rad2deg(x(2)),x(2));
fprintf('Thrus_trim: %6.10f N or %f lbs\n',sqrt(x(3)),sqrt(x(3))/4.448222);
disp('  ');
disp('------------------------------------------------------------------');
disp('  ');
X={x(1) x(2) sqrt(x(3)); 'rad' 'rad' 'N'}';
% delta_e = x(2);
% alpha = x(1);
% thrust = sqrt(x(3));
% attitude=[0,alpha,0];
% vel = [nfs.crusevel*cos(alpha), 0, nfs.crusevel*sin(alpha)]';
% [force,moment]=ForceMoment(vel,[0,0,0]',[delta_e,0,0,0],attitude,[0,0,nfs.altitude],thrust,0,nfs);
% disp(force);
% disp(moment);
end

function fun_val=TrimCost(x,nfs)
alpha=x(1);
delta_e=x(2);
thrust=abs(x(3));

% abs has been added since the negative values are not acceptable for
% thrust

p=0; q=0; r=0; delta_f=0; delta_a=0;

linvel=[nfs.crusevel*cos(alpha), 0, nfs.crusevel*sin(alpha)]'; 
angvel=[p, q, r]';
control=[delta_f, delta_e, delta_a]';
attitude=[0,alpha,0]';
height=abs(nfs.altitude);
cgloc=[0,0,0]';
u=[linvel;angvel;control;attitude;height;thrust;cgloc];
assignin('base','u',u);% assignin('base','t',[0*ones(size(u)) .1*ones(size(u))]);
evalin('base','sim(''DatcomForceMoment'');');
fun_val = evalin('base','y');
if abs(delta_e)>deg2rad(50)||abs(alpha)>deg2rad(20)
    fun_val=1e10;
end;

% nfs.trim.thrust=thrust;
% if thrust<0, error('Negative Value'); end;
% [F_Body,M_Body]=ForceMoment(vel,[0,0,0]',[delta_e,0,0,0],attitude,[0,0,nfs.altitude],thrust,t,nfs);
% fun_val=[F_Body;
%          M_Body];
end

%-------------------------------------------------------------------------%

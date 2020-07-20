% Simulation plotter
% function Plotter()
results = evalin('base','nfs.Results');
res_ned_pos = results.NED.Position;
res_euler_angs = results.Euler;
res_angvel = results.Body.Angular.Vel;
res_angvel = reshape(res_angvel,[3,length(res_angvel)])';
control_commands = results.Control;
tout = results.Time;

set(0,'Units','pixels') 
scnsize = get(0,'ScreenSize');
h1=figure('NumberTitle','off','Name','Position',...'Menubar','none',...
    'color',[1,1,1]);
position=get(h1,'Position');
outerpos=get(h1,'OuterPosition');
borders=outerpos - position;

pos_margin = 1; % this is used to plot trajectory with proper scale

plot3(res_ned_pos(:,1),res_ned_pos(:,2),(res_ned_pos(:,3)),'Color',	'#7E2F8E','LineWidth',2);
hold on; xlabel('X^{L}'); ylabel('Y^{L}'); zlabel('Z^{L}'); 
axis([min(res_ned_pos(:,1))-pos_margin, max(res_ned_pos(:,1))+pos_margin,...
      min(res_ned_pos(:,2))-pos_margin, max(res_ned_pos(:,2))+pos_margin,...
      min(res_ned_pos(:,3))-pos_margin*2, max(res_ned_pos(:,3))+pos_margin*2])
title('Airplane Trajectory in Local Coordinate');
grid on; grid minor; rotate3d;


h2=figure('NumberTitle','off','Name','Attitude',...'Menubar','none',...
    'Color',[1,1,1]);
eulermargin = 0.01;
subplot(3,1,1); plot(tout,res_euler_angs(:,1));
ax=axis; axis([ax(1) ax(2) min(res_euler_angs(:,1))-eulermargin max(res_euler_angs(:,1))+eulermargin]);
ylabel('\phi [deg]');title('Euler Angles'); grid on; grid minor;
subplot(3,1,2); plot(tout,res_euler_angs(:,2));
ax=axis; axis([ax(1) ax(2) min(res_euler_angs(:,2))-eulermargin max(res_euler_angs(:,2))+eulermargin]);
ylabel('\theta [deg]'); grid on; grid minor;
subplot(3,1,3); plot(tout,res_euler_angs(:,3));
ax=axis; axis([ax(1) ax(2) min(res_euler_angs(:,3))-eulermargin max(res_euler_angs(:,3))+eulermargin]);
ylabel('\psi [deg]');xlabel('Time [sec]');  grid on; grid minor;zoom();


h3 = figure('NumberTitle','off','Name','Control Commands',...'Menubar','none',...
    'Color',[1,1,1]);
ccomands=zeros(length(tout),4);
ccomands(:,1)=rad2deg(control_commands(1,1,:));
ccomands(:,2)=rad2deg(control_commands(2,1,:));
ccomands(:,3)=rad2deg(control_commands(3,1,:));
ccomands(:,4)=rad2deg(control_commands(4,1,:));
control_commands=ccomands;
subplot(4,1,1); plot(tout,control_commands(:,1));
if min(control_commands(:,1)) > 0,
    ax=axis; axis([ax(1) ax(2) 0.95*min(control_commands(:,1)) 1.05*max(control_commands(:,1))]);
elseif max(control_commands(:,1)) < 0,
    ax=axis; axis([ax(1) ax(2) 1.05*max(control_commands(:,1)) 0.95*min(control_commands(:,1))]);
end;
ylabel('\delta_{e} [deg]');title('Control Commands'); grid on; grid minor;
subplot(4,1,2); plot(tout,control_commands(:,2));
ylabel('\delta_{F} [deg]'); grid on; grid minor;
subplot(4,1,3); plot(tout,control_commands(:,3));
ylabel('\delta_{a} [deg]');xlabel('Time [sec]'); grid on; grid minor;
subplot(4,1,4); plot(tout,control_commands(:,4));
ylabel('\delta_{r} [deg]');xlabel('Time [sec]'); grid on; grid minor;
zoom;


h4 = figure('NumberTitle','off','Name','Reserve Figure',...'Menubar','none',...
    'Color',[1,1,1]);
angvelmargin = 0.0005;
subplot(3,1,1); plot(tout,res_angvel(:,1));
ax=axis; axis([ax(1) ax(2) min(res_angvel(:,1))-angvelmargin max(res_angvel(:,1))+angvelmargin]);
ylabel('p [rad/sec]');title('Angular Velocity'); grid on; grid minor;
subplot(3,1,2); plot(tout,res_angvel(:,2));
ax=axis; axis([ax(1) ax(2) min(res_angvel(:,2))-angvelmargin max(res_angvel(:,2))+angvelmargin]);
ylabel('q [rad/sec]'); grid on; grid minor;
subplot(3,1,3); plot(tout,res_angvel(:,3));
ax=axis; axis([ax(1) ax(2) min(res_angvel(:,3))-angvelmargin max(res_angvel(:,3))+angvelmargin]);
ylabel('r [rad/sec]');xlabel('Time [sec]'); grid on; grid minor; zoom();


edge = -borders(1)/8;
pos1 = [edge,...
        scnsize(4) * (1/2),...
        scnsize(3)/2 - edge,...
        scnsize(4)/2];
pos2 = [scnsize(3)/2 + edge,...
        pos1(2),...
        pos1(3),...
        pos1(4)];
pos3 = [edge,...
        0 * scnsize(4) * (1/2),...
        scnsize(3)/2 - edge,...
        scnsize(4)/2];
pos4 = [scnsize(3)/2 + edge,...
        pos3(2),...
        pos3(3),...
        pos3(4)];
set(h1,'OuterPosition',pos1);
set(h2,'OuterPosition',pos2);
set(h3,'OuterPosition',pos3);
set(h4,'OuterPosition',pos4);
% figure(h1); hold on;
% plot3(ned_position(:,1),ned_position(:,2),ned_position(:,3));
% comet3(ned_position(:,1),ned_position(:,2),ned_position(:,3));

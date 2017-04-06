% Simulation plotter
function Plotter(ned_position,euler_angles,control_commands,tout)
set(0,'Units','pixels') 
scnsize = get(0,'ScreenSize');
h1=figure('NumberTitle','off','Name','Position',...'Menubar','none',...
    'color',[1,1,1]);
position=get(h1,'Position');
outerpos=get(h1,'OuterPosition');
borders=outerpos - position;
plot3(ned_position(:,1),ned_position(:,2),(ned_position(:,3)),'y','LineWidth',2);
hold on; xlabel('X^{L}'); ylabel('Y^{L}'); zlabel('Z^{L}'); pos_margin=5;
axis([min(ned_position(:,1))-pos_margin, max(ned_position(:,1))+pos_margin,...
      min(ned_position(:,2))-pos_margin, max(ned_position(:,2))+pos_margin,...
      min(ned_position(:,3))-pos_margin, max(ned_position(:,3))+pos_margin])
title('Airplane Trajectory in Local Coordinate');
grid on; rotate3d;
h2=figure('NumberTitle','off','Name','Attitude',...'Menubar','none',...
    'Color',[1,1,1]);
subplot(3,1,1); plot(tout,euler_angles(:,1));
ax=axis; axis([ax(1) ax(2) min(euler_angles(:,1))-1 max(euler_angles(:,1))+1]);
ylabel('\phi [deg]');title('Euler Angles');
subplot(3,1,2); plot(tout,euler_angles(:,2));
% ax=axis; axis([ax(1) ax(2) min(euler_angles(:,2))-1 max(euler_angles(:,2))+1]);
ylabel('\theta [deg]');
subplot(3,1,3); plot(tout,euler_angles(:,3));
ax=axis; axis([ax(1) ax(2) min(euler_angles(:,3))-1 max(euler_angles(:,3))+1]);
ylabel('\psi [deg]');xlabel('Time [sec]');
zoom;
h3 = figure('NumberTitle','off','Name','Control Commands',...'Menubar','none',...
    'Color',[1,1,1]);
ccomands=zeros(length(tout),4);
ccomands(:,1)=control_commands(1,1,:);
ccomands(:,2)=control_commands(2,1,:);
ccomands(:,3)=control_commands(3,1,:);
ccomands(:,4)=control_commands(4,1,:);
control_commands=ccomands;
subplot(4,1,1); plot(tout,control_commands(:,1)); axis tight;
ylabel('\delta_{e} [rad]');title('Control Commands');
subplot(4,1,2); plot(tout,control_commands(:,2));
ylabel('\delta_{F} [rad]');
subplot(4,1,3); plot(tout,control_commands(:,3));
ylabel('\delta_{a} [rad]');xlabel('Time [sec]');
subplot(4,1,4); plot(tout,control_commands(:,4));
ylabel('\delta_{r} [rad]');xlabel('Time [sec]');
zoom;
h4 = figure('NumberTitle','off','Name','Reserve Figure',...'Menubar','none',...
    'Color',[1,1,1]);
edge = -borders(1)/2;
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

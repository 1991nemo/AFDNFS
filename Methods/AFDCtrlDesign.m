function nfs = AFDCtrlDesign(nfs)
%% lqr design
Along = nfs.dyn.long.ss.A;
Blong = nfs.dyn.long.ss.B;
Clong = eye(size(Along));
Dlong = zeros(size(Clong,1),size(Blong,2));

syslong = ss(Along, Blong, Clong, Dlong);

Qlong = eye(size(Along))*1;%diag([50 50 600 400]);

[Klong, ~, ~] = lqr(syslong,Qlong,1*eye(size(Blong,2)));

nfs.ctrl.lqr.long.K = Klong;

% eliminating Psi
Alat = nfs.dyn.lat.ss.A;
Blat = nfs.dyn.lat.ss.B;
Clat = eye(size(Alat));
Dlat = zeros(size(Clat,1),size(Blat,2));

syslat = ss(Alat, Blat, Clat, Dlat);

Qlat = diag([50 600 600 400 400]);

[Klat, ~, ~] = lqr(syslat,Qlat,eye(size(Blat,2)));

nfs.ctrl.lqr.lat.K = Klat;


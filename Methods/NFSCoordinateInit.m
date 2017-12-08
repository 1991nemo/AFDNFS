function nfs = NFSCoordinateInit(nfs)
nfs.Coordinate.Ref  = 'NED'  ;
nfs.Coordinate.Lat  = 35.6892; % [deg] - North positive
nfs.Coordinate.Long = 51.3890; % [deg] - East  positive
nfs.Coordinate.Alt  = -1250  ; % [ m ] - Down  positive - zero @ mean sea level

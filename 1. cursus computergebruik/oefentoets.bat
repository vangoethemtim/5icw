@echo off
setlocal

rem ============================================
rem TOETS A - COMPUTERGEbruik
rem ============================================

set "WERKMAP=%USERPROFILE%\ComputerGebruik\ToetsA"

rem Werkmap maken indien nodig
if not exist "%WERKMAP%" mkdir "%WERKMAP%"

rem Naar de werkmap gaan
cd /d "%WERKMAP%"

rem ============================================
rem 1. CONTROLEBESTAND
rem ============================================

echo Naam: Jouw naam>controle.txt
echo Klas: 5ICW>>controle.txt
echo Windows-gebruiker: %USERNAME%>>controle.txt
echo Computer: %COMPUTERNAME%>>controle.txt
echo Profiel: %USERPROFILE%>>controle.txt
echo Huidig pad: %CD%>>controle.txt

rem ============================================
rem 2. MAPPENSTRUCTUUR
rem ============================================

mkdir documentatie
mkdir archief
mkdir systeem

rem ============================================
rem 3. TEKSTBESTAND
rem ============================================

echo Computergebruik - Toets A>documentatie\concept.txt
echo Gebruiker: %USERNAME%>>documentatie\concept.txt
echo Computer: %COMPUTERNAME%>>documentatie\concept.txt

ren documentatie\concept.txt verslag.txt

echo.>>controle.txt
echo ===== INHOUD VERSLAG =====>>controle.txt
type documentatie\verslag.txt>>controle.txt

rem ============================================
rem 4. KOPIEREN EN VERPLAATSEN
rem ============================================

copy documentatie\verslag.txt reservekopie.txt
move reservekopie.txt archief\reservekopie.txt

rem ============================================
rem 5. VERBORGEN BESTAND
rem ============================================

echo Dit bestand is verborgen.>systeem\intern.txt
attrib +h systeem\intern.txt

echo.>>controle.txt
echo ===== ATTRIB INTERN.TXT =====>>controle.txt
attrib systeem\intern.txt>>controle.txt

rem ============================================
rem 6. AUTOMATISCHE CONTROLE
rem ============================================

echo.>>controle.txt
echo ===== WHOAMI =====>>controle.txt
whoami>>controle.txt

echo.>>controle.txt
echo ===== LOCATIE NOTEPAD =====>>controle.txt
where notepad>>controle.txt

echo.>>controle.txt
echo ===== MAPPENBOOM =====>>controle.txt
tree /f>>controle.txt

echo.>>controle.txt
echo ===== DIR /A SYSTEEM =====>>controle.txt
dir /a systeem>>controle.txt

rem Controlebestand tonen
cls
type controle.txt

pause
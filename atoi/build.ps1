$out = (javac -d build Main.java 2>&1)
if($out.Length -eq 0){
    java -cp .\build Main
}else{
    Write-Output $out
}
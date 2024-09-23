# 获取文件的总大小
$response = Invoke-WebRequest -Uri https://aka.ms/wslubuntu2204 -Method Head
$totalBytes = [int64]$response.Headers['Content-Length']

# 已下载的字节数
$downloadedBytes = 1032224768

# 计算剩余的字节数
$remainingBytes = $totalBytes - $downloadedBytes

Write-Output "$totalBytes"
Write-Output "$downloadedBytes"
Write-Output "$remainingBytes"
#include <windows.h>
#include <wia.h>
#include <iostream>
#include <comdef.h>

#pragma comment(lib, "wia.lib")

int main() {
    HRESULT hr;
    IWiaItem2* pWiaItem = NULL;
    IWiaItem2* pWiaChildItem = NULL;
    IEnumWiaItem2* pEnum = NULL;
    IWiaTransfer* pTransfer = NULL;
    IWiaTransferCallback* pp = NULL;

    // Inisialisasi COM
    CoInitialize(NULL);

    // Membuat instance manager perangkat WIA

    // Enumerasi perangkat WIA yang terhubung

    // Dapatkan perangkat pertama
    hr = pEnum->Next(1, &pWiaItem, NULL);
    if (FAILED(hr) || pWiaItem == NULL) {
        std::cerr << "Tidak ada perangkat yang ditemukan" << std::endl;
        return -1;
    }

    // Mengambil perangkat anak (misalnya, item gambar pertama)
 
    // Membuat objek transfer untuk mentransfer gambar
    hr = pWiaChildItem->QueryInterface(IID_IWiaTransfer, (void**)&pTransfer);
    if (FAILED(hr)) {
        std::cerr << "Gagal membuat objek transfer" << std::endl;
        return -1;
    }

    // Menangkap gambar dari perangkat
    hr = pTransfer->Download(NULL, pp);
    if (FAILED(hr)) {
        std::cerr << "Gagal menangkap gambar" << std::endl;
        return -1;
    }

    std::cout << "Gambar berhasil diambil!" << std::endl;

    // Cleanup
    if (pTransfer) pTransfer->Release();
    if (pWiaChildItem) pWiaChildItem->Release();
    if (pWiaItem) pWiaItem->Release();
    if (pEnum) pEnum->Release();

    CoUninitialize();

    return 0;
}


// I'm working student 


#include "framework.h"
#include "NewMain.h"
#include <sstream>

#include <gl/GL.h>
#include <glext.h>

#include "openGLHeaders.h"
#include "shadersData.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <fstream>



#pragma comment(lib, "opengl32.lib")
#define MAX_LOADSTRING 100



#define WGL_DRAW_TO_WINDOW_ARB         0x2001
#define WGL_ACCELERATION_ARB           0x2003
#define WGL_SWAP_METHOD_ARB            0x2007
#define WGL_SUPPORT_OPENGL_ARB         0x2010
#define WGL_DOUBLE_BUFFER_ARB          0x2011
#define WGL_PIXEL_TYPE_ARB             0x2013
#define WGL_COLOR_BITS_ARB             0x2014
#define WGL_DEPTH_BITS_ARB             0x2022
#define WGL_STENCIL_BITS_ARB           0x2023
#define WGL_FULL_ACCELERATION_ARB      0x2027
#define WGL_SWAP_EXCHANGE_ARB          0x2028
#define WGL_TYPE_RGBA_ARB              0x202B
#define WGL_CONTEXT_MAJOR_VERSION_ARB  0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB  0x2092
#define GL_ARRAY_BUFFER                   0x8892
#define GL_STATIC_DRAW                    0x88E4
#define GL_FRAGMENT_SHADER                0x8B30
#define GL_VERTEX_SHADER                  0x8B31
#define GL_COMPILE_STATUS                 0x8B81
#define GL_LINK_STATUS                    0x8B82
#define GL_INFO_LOG_LENGTH                0x8B84
#define GL_TEXTURE0                       0x84C0
#define GL_BGRA                           0x80E1
#define GL_ELEMENT_ARRAY_BUFFER           0x8893




typedef BOOL(WINAPI* PFNWGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats,
    int* piFormats, UINT* nNumFormats);

typedef HGLRC(WINAPI* PFNWGLCREATECONTEXTATTRIBSARBPROC) (HDC hDC, HGLRC hShareContext, const int* attribList);
typedef BOOL(WINAPI* PFNWGLSWAPINTERVALEXTPROC) (int interval);

PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;
PFNGLUSEPROGRAMPROC glUseProgram;
PFNGLCREATEPROGRAMPROC glCreateProgram;
PFNGLCREATESHADERPROC glCreateShader;

PFNGLSHADERSOURCEPROC  glShaderSource;
PFNGLCOMPILESHADERPROC  glCompileShader;
PFNGLDELETESHADERPROC glDeleteShader;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
PFNGLGETSHADERIVPROC glGetShaderiv;
PFNGLATTACHSHADERPROC glAttachShader;
PFNGLLINKPROGRAMPROC glLinkProgram;
PFNGLVALIDATEPROGRAMPROC glValidateProgram;
PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
PFNGLBUFFERDATAPROC glBufferData;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
PFNGLBINDBUFFERPROC glBindBuffer;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
PFNGLGENBUFFERSPROC glGenBuffers;
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
PFNGLACTIVETEXTUREPROC glActiveTexture;
PFNGLUNIFORM1IPROC glUniform1i;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
PFNGLDELETEPROGRAMPROC glDeleteProgram;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArray;
PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;



const int32_t mWidth = 860; 
const int32_t mHeight = 620;


GLuint matrixDrawRectangle;
//LosMatrix4_4 PAL;


GLuint programDrawLines;
GLuint programGraph;
GLuint programBUtton;
GLuint mainVAO;
GLuint secondVAO;
GLuint buttonVAO;
GLuint diffTex2;

GLuint coptermainProgram;
GLuint compterVao;
GLuint matrixCompter, lightSpot1, lightSpot2, lightVolumeLightMain;



GLuint matrixDrawGraph;
float matrixButton[4][4];
static bool firstScreen = true;
bool LoadCont();

HGLRC ourOpenGLRenderingContext;
HDC ourWindowHandleToDeviceContext;
HDC m_deviceContext;
HGLRC m_renderingContext;
void HardRender();
void BuildGLProgramFirst();
GLuint BuildGLProgram(const char* shader1, const char* shader2);
bool CheckShaderBuild(GLuint& shaderF);

void* GetAnyGLFuncAddress(const char* name);

bool LoadFourFiveContextLoaded();
void CallingLoadingExtension();

HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];
void   BuildprogramsGL();;
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
inline void LosOutputStringConvert(const char* textMessages, int n);


void* GetAnyGLFuncAddress(const char* name)
{
    void* p = (void*)wglGetProcAddress(name);
    if (p == 0 ||
        (p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) ||
        (p == (void*)-1))
    {
        HMODULE module = LoadLibraryA("opengl32.dll");
        p = (void*)GetProcAddress(module, name);
    }

    return p;
}


void BuildprogramsGL() {


}

void CallingLoadingExtension() {

    glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
    glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
    glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
    glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
    glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
    glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
    glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
    glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
    glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");

    glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
    glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)wglGetProcAddress("glValidateProgram");
    glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
    glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
    glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
    glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
    glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
    glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
    glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
    glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
    glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
    glActiveTexture = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
    glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
    glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");

    glDeleteProgram = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
    glDeleteVertexArray = (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArray");
    wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
    wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
    wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
    glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)wglGetProcAddress("glCompressedTexImage2D");

}



inline void LosOutputStringConvert(const char* textMessages, int n = 0) {

    //WCHAR ss[128] = {};
    //ss = L"asdfwf";
   // wsprintf(ss, "my debg String == %s n", n.c_str());

    WCHAR EmptyMess[50] = L"Simple message to empty \n";
    //	std::string uyi{ "Mokihjuu" };


        //if (n == 3) {
            //kjj = L" ";
        //}
        //else {
        //	kjj = L" ";
        //}

    std::string newSteing = textMessages;
    std::wstring kjj(newSteing.size(), 0);
    MultiByteToWideChar(CP_UTF8, 0, &newSteing[0], (int)newSteing.size(), &kjj[0], newSteing.size());

    //std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    //std::string narrow = converter.to_bytes(uyi);
    // std::wstring wide = converter.from_bytes(narrow);

    if (n == 0) {
        wsprintfW(EmptyMess, L"copter: %s \n", kjj.c_str()); //
    }
    else {
        wsprintfW(EmptyMess, L"copter: %s %d \n", kjj.c_str(), n); //
    }

    OutputDebugStringW(EmptyMess);
    //EmptyMess = "";
}

static constexpr auto VERTEX_OFFSET = 0;

float destWidth;
float destHeight;
float n = 1.0f;



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {

    case WM_CREATE:
    {


        // LoadFourFiveContextLoaded();
        PIXELFORMATDESCRIPTOR pfd =
        {
            sizeof(PIXELFORMATDESCRIPTOR),
            1,
            PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
            PFD_TYPE_RGBA,
            32,
            0, 0, 0, 0, 0, 0,
            0,
            0,
            0,
            0, 0, 0, 0,
            24,
            8,
            0,
            PFD_MAIN_PLANE,
            0,
            0, 0, 0
        };

        ourWindowHandleToDeviceContext = GetDC(hWnd);

        destWidth = LOWORD(lParam);
        destHeight = HIWORD(lParam);

        int  letWindowsChooseThisPixelFormat;
        letWindowsChooseThisPixelFormat = ChoosePixelFormat(ourWindowHandleToDeviceContext, &pfd);
        SetPixelFormat(ourWindowHandleToDeviceContext, letWindowsChooseThisPixelFormat, &pfd);

        ourOpenGLRenderingContext = wglCreateContext(ourWindowHandleToDeviceContext);
        wglMakeCurrent(ourWindowHandleToDeviceContext, ourOpenGLRenderingContext);

        CallingLoadingExtension();

        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(ourOpenGLRenderingContext);
        ourOpenGLRenderingContext = NULL;

        // Release the device context for this window.
        ReleaseDC(hWnd, ourWindowHandleToDeviceContext);
        ourWindowHandleToDeviceContext = 0;

        int attributeListInt[19];
        int pixelFormat2[1];
        unsigned int formatCount;
        int result;
        PIXELFORMATDESCRIPTOR pixelFormatDescriptor;
        int attributeList[5];
        float fieldOfView, screenAspect;
        char* vendorString, * rendererString;



        // Get the device context for this window.
        m_deviceContext = GetDC(hWnd);
        if (!m_deviceContext)
        {
            LosOutputStringConvert("no device context");
            return false;
        }

        // Support for OpenGL rendering.
        attributeListInt[0] = WGL_SUPPORT_OPENGL_ARB;
        attributeListInt[1] = TRUE;

        // Support for rendering to a window.
        attributeListInt[2] = WGL_DRAW_TO_WINDOW_ARB;
        attributeListInt[3] = TRUE;

        // Support for hardware acceleration.
        attributeListInt[4] = WGL_ACCELERATION_ARB;
        attributeListInt[5] = WGL_FULL_ACCELERATION_ARB;

        // Support for 24bit color.
        attributeListInt[6] = WGL_COLOR_BITS_ARB;
        attributeListInt[7] = 24;

        // Support for 24 bit depth buffer.
        attributeListInt[8] = WGL_DEPTH_BITS_ARB;
        attributeListInt[9] = 24;

        // Support for double buffer.
        attributeListInt[10] = WGL_DOUBLE_BUFFER_ARB;
        attributeListInt[11] = TRUE;

        // Support for swapping front and back buffer.
        attributeListInt[12] = WGL_SWAP_METHOD_ARB;
        attributeListInt[13] = WGL_SWAP_EXCHANGE_ARB;

        // Support for the RGBA pixel type.
        attributeListInt[14] = WGL_PIXEL_TYPE_ARB;
        attributeListInt[15] = WGL_TYPE_RGBA_ARB;

        // Support for a 8 bit stencil buffer.
        attributeListInt[16] = WGL_STENCIL_BITS_ARB;
        attributeListInt[17] = 8;

        // Null terminate the attribute list.
        attributeListInt[18] = 0;

        int result1 = wglChoosePixelFormatARB(m_deviceContext, attributeListInt, NULL, 1, pixelFormat2, &formatCount);
        if (result1 != 1)
        {
            LosOutputStringConvert("Error to wglChoosePixelFormat", 21);
            return false;
        }

        result1 = SetPixelFormat(m_deviceContext, pixelFormat2[0], &pixelFormatDescriptor);
        if (result1 != 1)
        {
            LosOutputStringConvert("Error to serPixelPerfect", 21);
            return false;
        }

        attributeList[0] = WGL_CONTEXT_MAJOR_VERSION_ARB;
        attributeList[1] = 3; // was 4
        attributeList[2] = WGL_CONTEXT_MINOR_VERSION_ARB;
        attributeList[3] = 3; // was 2 

        // Null terminate the attribute list.
        attributeList[4] = 0;

        // Create a OpenGL 4.0 rendering context.
        m_renderingContext = wglCreateContextAttribsARB(m_deviceContext, 0, attributeList);
        if (m_renderingContext == NULL)
        {
            LosOutputStringConvert("no render context");
            return false;
        }

        // Set the rendering context to active.
        result1 = wglMakeCurrent(m_deviceContext, m_renderingContext);
        if (result1 != 1)
        {
            LosOutputStringConvert("sdf");
            return false;
        }

        wglSwapIntervalEXT(1);


        //  MessageBoxA(0, (char*)glGetString(GL_VERSION), "OPENGL VERSION", 0); // check creating openGL version 

         // TODO: building two program to main draw 
        BuildprogramsGL();

    }
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        switch (wmId)
        {
        case IDM_ABOUT:
            //DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            wglDeleteContext(ourOpenGLRenderingContext);
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
    }
    break;

    case WM_LBUTTONDOWN:
    {
        //LosOutputStringConvert("d);
        POINT pLos;
        ::GetCursorPos(&pLos);
        LosOutputStringConvert(" press buttons ", pLos.x);
        LosOutputStringConvert("press buttons ", pLos.y);


        RECT rectLos;
        ::GetClientRect(hWnd, &rectLos);
        LosOutputStringConvert("get this touch ");
        // LosOutputStringConvert(rectLos.left);
         //LosOutputStringConvert(rectLos.bottom);
        // LosOutputStringConvert(rectLos.right);
        // LosOutputStringConvert(rectLos.top);


    }
    break;


    case WM_DESTROY:


        //GLuint programDrawLines;
        GLuint mainVAO;
        GLuint secondVAO;
        GLuint buttonVAO;

        //glDeleteVertexArray(1, &mainVAO);
        //glDeleteVertexArray(1, &secondVAO);
        //glDeleteVertexArray(1, &buttonVAO);
        //glDeleteProgram(programDrawLines);



        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


#define IDC_RAYLOSA		99
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_RAYTRACINGOPENGL, szWindowClass, MAX_LOADSTRING);


    MyRegisterClass(hInstance);

    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_RAYTRACINGOPENGL));

    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        HardRender();
    }

    return (int)msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_RAYTRACINGOPENGL));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_RAYTRACINGOPENGL);
    // was szWindowClass

    wcex.lpszClassName = L"sdflk";
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance;

    const wchar_t CLASS_NAME[20] = L"Task 41 Work !";



    // was WS_CAPTION WS_OVERLAPPEDWINDOW 
    HWND hWnd = CreateWindowW(L"sdflk", CLASS_NAME, WS_OVERLAPPEDWINDOW,
        200, 200, mWidth, mHeight, nullptr, nullptr, hInstance, nullptr);
    ::SetMenu(hWnd, NULL);


    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}


void HardRender()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.211F, 0.207F, 0.2F, 1.0F);



    SwapBuffers(m_deviceContext); 
}
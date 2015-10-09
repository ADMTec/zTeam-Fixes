//test tron
#include "stdafx.h"
#include "Graphics.h"
#include "Glow.h"
#include <stdio.h>
#include <process.h>
 
Graphics gGraphics;
 
Graphics::Graphics()
{
        printf("Graphics::Graphics() Success.");
}
 
DWORD gTmpEax;
DWORD gTmpEcx;
DWORD gTmpEdx;
DWORD gTmpEbx;
DWORD gTmpEsp;
DWORD gTmpEbp;
DWORD gTmpEsi;
DWORD gTmpEdi;
 
DWORD gSelectEnter = 0x0040AB4A;
DWORD gGraphicsEnter = 0x00777B3B;
DWORD gSelectASMJmp00 = gSelectEnter + 6;
DWORD gGraphicsASM00Jmp00 = gGraphicsEnter + 5;
 
Naked (gSelectASM00)
{
        _asm
        {
                MOV gTmpEax,EAX
                MOV gTmpEsi,ESI
                MOV gTmpEdi,EDI
                MOV gTmpEcx,ECX
                MOV gTmpEdx,EDX
                MOV gTmpEbx,EBX
                MOV gTmpEsp,ESP
                MOV gTmpEbp,EBP
        }
        //----
        RenderScreenGlow();
        //----
        _asm
        {
                MOV EAX,gTmpEax
                MOV ESI,gTmpEsi
                MOV EDI,gTmpEdi
                MOV ECX,gTmpEcx
                MOV EDX,gTmpEdx
                MOV EBX,gTmpEbx
                MOV ESP,gTmpEsp
                MOV EBP,gTmpEbp
                ADD ECX,0x200
                //---
                JMP gSelectASMJmp00
        }
}
 
Naked (gGraphicsASM00)
{
        _asm
        {
                MOV gTmpEax,EAX
                MOV gTmpEsi,ESI
                MOV gTmpEdi,EDI
                MOV gTmpEcx,ECX
                MOV gTmpEdx,EDX
                MOV gTmpEbx,EBX
                MOV gTmpEsp,ESP
                MOV gTmpEbp,EBP
        }
        //----
        RenderScreenGlow();
        //----
        _asm
        {
                MOV EAX,gTmpEax
                MOV ESI,gTmpEsi
                MOV EDI,gTmpEdi
                MOV ECX,gTmpEcx
                MOV EDX,gTmpEdx
                MOV EBX,gTmpEbx
                MOV ESP,gTmpEsp
                MOV EBP,gTmpEbp
                PUSH 0x0
                MOV ECX,DWORD PTR SS:[EBP-0x4]
                //---
                JMP gGraphicsASM00Jmp00
        }
}
 
void Graphics::Load()
{
        SetOp((LPVOID)oInitGraphics_Call, this->InitGraphics, ASM::CALL);
        SetOp((LPVOID)oSelectDraw_Call, this->SelectDraw, ASM::CALL);
        //---
        SetRange((LPVOID)0x0040AB4A, 0x06, ASM::NOP);
        SetJmp((LPVOID)0x0040AB4A, gSelectASM00);
        //---
        SetRange((LPVOID)0x00777B3B, 0x05, ASM::NOP);
        SetJmp((LPVOID)0x00777B3B, gGraphicsASM00);
        //---
        printf("Graphics::Load() Success.\n");
}
 
void Graphics::InitGraphics()
{
    InitScreenGlow();
        //---
        pInitGraphics();
        //printf("Graphics::InitGraphics() Success.\n");
}
 
int Graphics::SelectDraw(int value)
{
        RenderScreenGlow();
        //---
        //printf("Graphics::SelectDraw() Success.\n");
        return pSelectDraw(value);     
}

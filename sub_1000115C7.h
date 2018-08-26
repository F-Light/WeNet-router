 aAbcdefghijklmn db 'abcdefghijklmnopqrstuvwxyz1234567890ZYXWVUTSRQPONMLKJIHGFEDCBA:_',0

__int64 __fastcall sub_1000115C7(__int64 a1, int a2, __int64 a3, signed int a4)
{                  

  signed int v4; // ebx                                                      
  __int64 v5; // r13                                                         
  __int64 v6; // r12                                                         
  __int64 v7; // r14                                                         
  int v8; // eax                                                             
  unsigned int v9; // ecx                                                    
  _BYTE *v10; // r12                                                         
  __int64 v11; // r14                                                        
  unsigned __int8 v12; // r15                                                
  unsigned int v13; // er13                                                  
  unsigned __int8 v14; // bl                                                 
  __int64 v15; // r14                                                        
  unsigned __int8 v16; // al                                                 
  __int64 v17; // r15                                                        
  int v19; // [rsp+8h] [rbp-58h]                                             
  signed int v20; // [rsp+10h] [rbp-50h]                                     
  int v21; // [rsp+18h] [rbp-48h]                                            
  __int64 v22; // [rsp+28h] [rbp-38h]                                        
  int v23; // [rsp+34h] [rbp-2Ch]                                            
                                                                             
  v4 = a4;                                                                   
  v22 = a3;                                                                  
  v5 = a1;                                                                   
  LODWORD(v6) = -1;                                                          
  if ( a1 )                                                                  
  {                                                                          
    if ( a2 > 0 )                                                            
    {                                                                        
      LODWORD(v6) = -2;                                                      
      if ( a3 )                                                              
      {                                                                      
        if ( a4 > 0 )                                                        
        {                                                                    
          LODWORD(v6) = -3;                                                  
          if ( 3 * ((signed int)(a4 + ((unsigned int)(a4 + 1) >> 31) + 1) >> 1) <= a2 )
          {                                                                  
            if ( dword_10002AB90 )                                           
            {                                                                
              v7 = a3;                                                       
              puts("-----");                                                 
              a3 = v7;                                                       
            }                                                                
            LODWORD(v6) = 0;                                                 
            v23 = v4 - 1;                                                    
            v8 = 0;                                                          
            if ( v4 > 1 )                                                    
            {                                                                
              v20 = v4;                                                      
              v9 = (unsigned int)(v4 - 2) >> 1;                              
              v21 = 3 * v9;                                                  
              v19 = 2 * v9;                                                  
              v10 = (_BYTE *)(a1 + 2);                                       
              v11 = 0LL;                                                     
              do                                                             
              {                                                              
                v12 = *(_BYTE *)(a3 + v11) >> 3;                             
                v13 = ((unsigned int)*(unsigned __int8 *)(a3 + v11 + 1) >> 6) | 4 * *(_BYTE *)(a3 + v11) & 0x1C;
                v14 = *(_BYTE *)(a3 + v11 + 1) & 0x3F;                       
                if ( dword_10002AB90 )                                       
                {                                                            
                  printf("%02x %02x %02x ", v12, v13, v14);                  
                  a3 = v22;                                                  
                }                                                            
                *(v10 - 2) = aAbcdefghijklmn[v12];                           
                *(v10 - 1) = aAbcdefghijklmn[v13];                           
                *v10 = aAbcdefghijklmn[v14];                                 
                v11 += 2LL;                                                  
                v10 += 3;                                                    
              }                                                              
              while ( (signed int)v11 < v23 );                               
              LODWORD(v6) = v21 + 3;                                         
              v8 = v19 + 2;                                                  
              v5 = a1;                                                       
              v4 = v20;                                                      
            }                                                                
            if ( v8 < v4 )                                                   
            {                                                                
              v15 = v8;                                                      
              v16 = *(_BYTE *)(a3 + v8);                                     
              if ( dword_10002AB90 )                                         
              {                                                              
                v17 = a3;                                                    
                printf("%02x %02x ", (unsigned int)v16 >> 3, 4 * v16 & 0x1C);
                a3 = v17;                                                    
                v16 = *(_BYTE *)(v17 + v15);                                 
              }                                                              
              v6 = (signed int)v6;                                           
              *(_BYTE *)(v5 + v6) = aAbcdefghijklmn[(unsigned __int64)v16 >> 3];
              *(_BYTE *)(v5 + v6 + 1) = aAbcdefghijklmn[4 * (*(_BYTE *)(a3 + v15) & 7)];
              *(_BYTE *)(v5 + v6 + 2) = 61;                                  
              LODWORD(v6) = v6 + 3;                                          
            }                                                                
            if ( dword_10002AB90 )                                           
              puts("\n-----");                                               
          }                                                                  
        }                                                                    
      }                                                                      
    }                                                                        
  }                        
                                                  
  return (unsigned int)v6;                                                   
}                                                                            
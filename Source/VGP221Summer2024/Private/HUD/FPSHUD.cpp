// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/FPSHUD.h"

void AFPSHUD::DrawHUD()
{
	Super::DrawHUD();

	if (!CrosshairTexture) UE_LOG(LogTemp, Warning, TEXT("Missing Crosshair Texture"));

	// Initializing FVector2D "Center" with x and y to 
	FVector2D Center(Canvas->ClipX / 2, Canvas->ClipY / 2);

	// 
	float CrosshairHalfWidth = (CrosshairTexture->GetSurfaceWidth() * 0.5f);
	float CrosshairHalfHeight = (CrosshairTexture->GetSurfaceHeight() * 0.5f);
	//Texture Pivot is Top-Left by default.
	FVector2D CrosshairDrawPos(Center.X - CrosshairHalfWidth, Center.Y - CrosshairHalfHeight);

	// Render Crosshair
	FCanvasTileItem TileItem(CrosshairDrawPos, CrosshairTexture->GetResource(), FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
}

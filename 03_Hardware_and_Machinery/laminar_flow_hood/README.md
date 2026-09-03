# 🌬️ Custom Horizontal Laminar Flow Hood (HEPA H14)

Documentation, airflow calculations, and Bill of Materials (BOM) for the custom-built horizontal laminar flow hood designed for sterile tissue culture and fungal transfers.

## Core Airflow Specifications
* **Target Laminar Velocity:** $0.45\text{ m/s}$ ($\approx 90\text{ FPM}$)
* **HEPA Filter Rating:** H14 ($99.995\%$ efficiency at $0.3\text{ }\mu\text{m}$)
* **Pre-Filter Rating:** G4 / MERV 8 (pleated particle pre-filter)

## Airflow Dimensioning Calculation
$$\text{Airflow Volume } (Q) = \text{Filter Area } (A) \times \text{Face Velocity } (V)$$

For a $610\text{ mm} \times 610\text{ mm}$ filter face ($0.372\text{ m}^2$):
$$Q = 0.372\text{ m}^2 \times 0.45\text{ m/s} = 0.1674\text{ m}^3\text{/s} \approx 602.6\text{ m}^3\text{/h} \quad (355\text{ CFM})$$

*Blower requirement:* Minimum $600-650\text{ m}^3\text{/h}$ at the total static pressure drop (HEPA + Pre-filter $\approx 250-350\text{ Pa}$).

## Bill of Materials (BOM)

| Component | Specifications | Qty | Role |
| :--- | :--- | :--- | :--- |
| **HEPA Filter** | H14 $610 \times 610 \times 78\text{ mm}$ (Aluminum frame) | 1 | Final particle filtration ($0.3\text{ }\mu\text{m}$) |
| **Blower Fan** | Centrifugal Forward Curved Blower ($>650\text{ m}^3\text{/h}$) | 1 | High-pressure air delivery |
| **Pre-Filter** | G4 Pleated Panel ($50\text{ mm}$ depth) | 1 | Gross dust capture to extend HEPA lifespan |
| **Enclosure** | $18\text{ mm}$ Coated Marine Plywood / Melamine | - | Air-tight plenum chamber frame |

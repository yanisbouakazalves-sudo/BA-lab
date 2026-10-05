# Batch Tracker — Supabase

Source versionnée du backend Supabase du BA Labs Batch Tracker.

## Projet Supabase

Project ref:

axcouwiodqsauwnsiotn

## Frontend

Le frontend actuel est :

batch-tracker/index.html

## Edge Functions

Fonction actuellement déployée :

claim-ba-labs

## Workflow Batch

Le workflow standard actuellement appliqué en production est :

preparation
→ sterilization
→ inoculation
→ incubation
→ cultivation
→ harvest
→ formulation
→ packaging
→ qc
→ release

L'étape QC ne peut pas être franchie par l'avancement standard.
La libération doit passer par release_batch() après validation des contrôles QC.

## Migrations présentes en production

20260930002507 — balabs_core_v1_1_1
20260930002521 — balabs_core_v1_1_1_fk_indexes
20261001215359 — add_batch_tracking_v1
20261001215407 — complete_batch_tracking_indexes_and_stages
20261001221338 — add_batch_workflow_rpc_v1
20261001223719 — add_batch_qc_release_v1
20261001224930 — add_qc_templates_v1
20261002154849 — seed_ba_labs_core_v1
20261003100557 — seed_ba_labs_references_v1
20261003100817 — seed_ba_labs_media_v1
20261003100916 — seed_ba_labs_strains_v1
20261003101003 — seed_ba_labs_material_generations_v1
20261003101043 — add_culture_generation_rpc_v1
20261003101130 — add_culture_creation_options_v1
20261003204716 — grant_authenticated_usage_private_schema_v1
20261003204826 — fix_culture_generation_material_code_ambiguity_v1
20261003204933 — fix_culture_created_event_subject_v1
20261003205156 — fix_culture_generation_rpc_result_v1
20261004210134 — fix_batch_qc_release_transition_v2
20261004210226 — lock_batch_creation_workflow_v1
20261004210540 — complete_release_stage_state_v1
20261004210813 — remove_redundant_indexes_v1

## Important
